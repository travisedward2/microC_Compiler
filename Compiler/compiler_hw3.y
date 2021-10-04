/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    #define codegen(...) \
        do { \
            for (int i = 0; i < INDENT; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    extern char* yytext;
    
    /* Other global variables */
    FILE *fout = NULL;
    bool HAS_ERROR = false;
    int INDENT = 0;
    int tag=0;
    int ltag=0;
    int itag=0;
    int elif=0;
    
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }
    typedef struct variable
    {
        int index;
        char* name;
        char* type;
        int address;
        int lineno;
        char* element_type;
        struct variable* next;
    }variable;

    variable* sym_tb=NULL; //head of each symbol_tables
    int level=0; //scope level 
    int myIndex=0;//current index
    int address=0;//address
    /* Symbol table function - you can add new function if needed. */
    void dump_symbol();
    void insert_variable( char* name , char*type,int lineno,char* element_type );
     void create_symbol();
     char* eletype_of(char* name);
     char* type_of(char* name);
     int  line_of(char* name);
     bool check_whole(char* name);
     bool check_entry(char* name);
     int address_of(char* name);

%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    /* ... */
}
/* Token without return */
/* Token without return */
%token INT FLOAT BOOL STRING INC DEC
%token SEMICOLON
%token PRINT
%token OR AND NOT
%token WHILE
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token IF ELSE 
%token LEQ GEQ EQL NEQ
%token FOR

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <s_val> IDENT
%token <s_val> TRUE FALSE
/* %token <s_val> FALSE */

/* Nonterminal with return, which need to sepcify type */




%type <s_val> typename expression
%type <s_val> andexpr cmpexpr addexpr mulexpr unaryexpr literal id  assignstmt simpleexpr incdecstmt arraysub
/* Yacc will start at this nonterminal */
%start program

/* --------------------------------------------------------------------------------------------------------- */
/* Grammar section */
%%

program
    : statementlist
;


statementlist
    : statementlist statement
    | statement  
 ;
/* type
    : typename 
; */

typename
    : INT  {$$="int";}
    | FLOAT {$$="float";}
    | STRING    {$$="string";}
    | BOOL  {$$="bool";}
;

literal
    : INT_LIT {
        printf("INT_LIT %d\n", $<i_val>$);
        codegen("ldc %d\n", $<i_val>$);
        $$="int";
    }
    | FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $<f_val>$);
        codegen("ldc %f\n", $<f_val>$);
        $$="float";
    }
    | STRING_LIT{
         printf("STRING_LIT %s\n", $<s_val>$);
        codegen("ldc \"%s\"\n", $<s_val>$);
         $$="string";
    }

    |TRUE {
        printf("TRUE\n");
        codegen("ldc 1\n");
        $$="bool";
        }
    |FALSE {
        codegen("ldc 0\n");
        printf("FALSE\n");
        $$="bool";
    }
;

id 
    : IDENT   {
        if(check_whole($1)){
            printf("IDENT (name=%s, address=%d)\n",$1,address_of($1));
            
            $$=$1;
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: undefined: %s\n",yylineno,$1);
            $$="error";
        }
       


    }
;
statement
    : declarationstmt   SEMICOLON 
    | expression    SEMICOLON
    | incdecstmt  SEMICOLON
    | printstmt
    | whilestmt
    | begin_block statement end_block
    | assignstmt SEMICOLON
    | ifstmt 
    | forstmt
    /* | Block
    | IfStmt
    | LoopStmt
    | PrintStmt */
;
forstmt
    :    FOR '(' forclause ')' begin_block {fprintf(fout,"For_Body%d:\n",level-1);} statementlist{codegen("goto Arith%d\n",level-1);} end_block {fprintf(fout,"For_End%d:\n",level);}
    ;
forclause
    : simpleexpr  SEMICOLON {fprintf(fout,"Condition%d:\n",level); } condition {codegen("ifeq For_End%d\n",level);  codegen("goto For_Body%d\n",level);} SEMICOLON  {fprintf(fout,"Arith%d:\n",level);} simpleexpr{ codegen("goto Condition%d\n",level);} 
    ;
/* forstmt
    :    FOR '(' forclause ')' begin_block statementlist end_block {codegen("goto For_begin_%d\n",level); fprintf(fout,"For_exit_%d:\n",level);}
    ;
forclause
    : simpleexpr  SEMICOLON {codegen("iload %d\n",address_of($1)); codegen("istore 90\n"); fprintf(fout,"For_begin_%d :\n",level);codegen("iload 90\n"); codegen("istore %d\n",address_of($1));} condition{codegen("ifeq For_exit_%d\n",level);} SEMICOLON simpleexpr{
            codegen("iload %d\n",address_of($1));
            codegen("istore 91\n");
            codegen("iload 90\n");
            codegen("istore %d\n",address_of($1));
            codegen("iload 91\n");
            codegen("istore 90\n");
        }
    ; */
simpleexpr
    : assignstmt 
    |expression
    | incdecstmt
    ;
ifstmt
    : frontif  ELSE    begin_block   statementlist   end_block {fprintf(fout,"IF_EXIT_%d:\n",level+1); if(level==0){itag+=10;} elif=0;}
    | frontif   ELSE  ifstmt
    | frontif {fprintf(fout,"IF_EXIT_%d:\n",level+1); if(level==0){itag+=10;} elif=0;}
    ;
    /* {codegen("ifeq IF_FALSE_%d\n",level+itag); }
    {fprintf(fout,"ifeq IF_FALSE_%d\n",level+itag); } 
     {codegen("goto IF_EXIT_%d\n",level+itag); }
     {fprintf(fout,"IF_EXIT_%d:\n",level+itag); if(level==0){itag+=10;elif=0;}
     { fprintf(fout,"IF_FALSE_%d:\n",level+itag+1);  if(level==0) {itag+=10; elif=0;}}*/
frontif
    : IF '(' condition ')' begin_block  {codegen("ifeq IF_FALSE_%d\n",level+itag+elif); }  statementlist {codegen("goto IF_EXIT_%d\n",level);  fprintf(fout,"IF_FALSE_%d:\n",level+itag+elif); elif++; } end_block  
    ;

assignstmt
    : id '=' expression {
        $$=$1;
        if(strcmp(type_of($1),$3)!=0 && strcmp($1,"error")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n",yylineno,type_of($1),$3);       
        }
        printf("ASSIGN\n");
        if(strcmp(type_of($1),"int")==0){
            codegen("istore %d\n",address_of($1));
        }
        else if(strcmp(type_of($1),"float")==0){
            codegen("fstore %d\n",address_of($1));
        }
        else if(strcmp(type_of($1),"bool")==0){
            codegen("istore %d\n",address_of($1));
        }
        else if(strcmp(type_of($1),"string")==0){
            codegen("astore %d\n",address_of($1));
        }
    }
    | id ADD_ASSIGN expression {
            printf("ADD_ASSIGN\n");
            if(strcmp(type_of($1),"int")==0){
                codegen("iload %d\n",address_of($1));
                codegen("iadd\n");
                codegen("istore %d\n",address_of($1));
            }
            else if(strcmp(type_of($1),"float")==0){
                codegen("fload %d\n",address_of($1));
                codegen("fadd\n");
                codegen("fstore %d\n",address_of($1));
            }


        }
    | id SUB_ASSIGN expression {
            printf("SUB_ASSIGN\n");
            if(strcmp(type_of($1),"int")==0){
                codegen("iload %d\n",address_of($1));
                codegen("isub\n");
                codegen("ineg\n");
                codegen("istore %d\n",address_of($1));
            }
            else if(strcmp(type_of($1),"float")==0){
                codegen("fload %d\n",address_of($1));
                codegen("fsub\n");
                codegen("fneg\n");
                codegen("fstore %d\n",address_of($1));
            }
    
        }
    | id MUL_ASSIGN expression {
            printf("MUL_ASSIGN\n");
            if(strcmp(type_of($1),"int")==0){
                codegen("iload %d\n",address_of($1));
                codegen("imul\n");
                codegen("istore %d\n",address_of($1));
            }
            else if(strcmp(type_of($1),"float")==0){
                codegen("fload %d\n",address_of($1));
                codegen("fmul\n");
                codegen("fstore %d\n",address_of($1));
            }

        }
    | id QUO_ASSIGN expression {
            printf("QUO_ASSIGN\n");
            if(strcmp(type_of($1),"int")==0){
                codegen("istore 84\n");
                codegen("iload %d\n",address_of($1));
                codegen("iload 84\n");
                codegen("idiv\n");
                codegen("istore %d\n",address_of($1));
            }
            else if(strcmp(type_of($1),"float")==0){
                codegen("fstore 84\n");
                codegen("fload %d\n",address_of($1));
                codegen("fload 84\n");
                codegen("fdiv\n");
                codegen("fstore %d\n",address_of($1));
            }

        }
    | id REM_ASSIGN expression {
        
            printf("REM_ASSIGN\n");
            if(strcmp(type_of($1),"int")==0){
                codegen("istore 85\n");
                codegen("iload %d\n",address_of($1));
                codegen("iload 85\n");
                codegen("irem\n");
                codegen("istore %d\n",address_of($1));
                
            }


        }
    | id '[' expression ']' '=' expression {
            printf("ASSIGN\n");

            if(strcmp(eletype_of($1),"int")==0){
                codegen("istore 82\n"); 
                codegen("istore 83\n");   
                codegen("aload %d\n",address_of($1));
                codegen("iload 83\n");  
                codegen("iload 82\n");  
                codegen("iastore\n");
            }
            else if(strcmp(eletype_of($1),"float")==0){
                codegen("fstore 82\n"); 
                codegen("istore 83\n");   
                codegen("aload %d\n",address_of($1));
                codegen("iload 83\n");  
                codegen("fload 82\n");  
                codegen("fastore\n");
            }
            
            
        }
    | id '[' expression ']' ADD_ASSIGN expression {printf("ADD_ASSIGN\n");}
    | id '[' expression ']' MUL_ASSIGN expression {printf("MUL_ASSIGN\n");}
    | id '[' expression ']' SUB_ASSIGN expression {printf("SUB_ASSIGN\n");}
    | id '[' expression ']' QUO_ASSIGN expression {printf("QUO_ASSIGN\n");}
    | id '[' expression ']' REM_ASSIGN expression {printf("REM_ASSIGN\n");}
    | literal '=' expression {   
        HAS_ERROR=true;
        printf("error:%d: cannot assign to %s\n",yylineno,$1);
        printf("ASSIGN\n");
        }
    | literal ADD_ASSIGN expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("ADD_ASSIGN\n");}
    | literal SUB_ASSIGN expression {HAS_ERROR=true; printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("SUB_ASSIGN\n");}
    | literal MUL_ASSIGN expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("MUL_ASSIGN\n");}
    | literal QUO_ASSIGN expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("QUO_ASSIGN\n");}
    | literal REM_ASSIGN expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("REM_ASSIGN\n");}
    | literal '[' expression ']' '=' expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("ASSIGN\n");}
    | literal '[' expression ']' ADD_ASSIGN expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("ADD_ASSIGN\n");}
    | literal '[' expression ']' MUL_ASSIGN expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("MUL_ASSIGN\n");}
    | literal '[' expression ']' SUB_ASSIGN expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("SUB_ASSIGN\n");}
    | literal '[' expression ']' QUO_ASSIGN expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("QUO_ASSIGN\n");}
    | literal '[' expression ']' REM_ASSIGN expression {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,$1); printf("REM_ASSIGN\n");}

;

whilestmt
    :WHILE '('{ fprintf(fout,"While_begin_%d :\n",level+ltag);} condition ')' {codegen("ifeq While_exit_%d\n",level+ltag);} begin_block statementlist end_block {
            codegen("goto While_begin_%d\n",level+ltag);
            fprintf(fout,"While_exit_%d:\n",level+ltag);
            if(level==0){
                ltag+=10;
            }
            
    }
    ;
condition
    :expression {
        if(strcmp($1,"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: non-bool (type %s) used as for condition\n",yylineno+1,$1);
        }
    }
    ;
begin_block
: '{' {create_symbol();}
;

end_block
: '}' {
    dump_symbol();
    }
;

printstmt
    : PRINT '('   expression  ')' SEMICOLON { 
          printf("PRINT %s\n",$3);
          if(strcmp($3,"int")==0){
                codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                codegen("swap\n");
                codegen("invokevirtual java/io/PrintStream/print(I)V\n");
          }
          else  if(strcmp($3,"float")==0){
                codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                codegen("swap\n");
                codegen("invokevirtual java/io/PrintStream/print(F)V\n");
          }
          else  if(strcmp($3,"bool")==0){
                codegen("ifne BOOL_%d\n",tag);
                tag++;
                codegen("ldc \"false\"\n");
                codegen("goto BOOL_%d\n",tag);
                fprintf(fout,"BOOL_%d:\n",tag-1);
                codegen("ldc \"true\"\n");
                fprintf(fout,"BOOL_%d:\n",tag);
                codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                codegen("swap\n");
                codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                tag++;

          }
          else  if(strcmp($3,"string")==0){
                codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                codegen("swap\n");
                codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
          }
                              
    }
    ;

incdecstmt:
    /* : INC id    [SEMICOLON]  { printf("INC\n");}
    | DEC id    [SEMICOLON]  { printf("DEC\n");} */
      id INC  { 
          $$=$1;
            if(strcmp(type_of($1),"int")==0){
                    codegen("iload %d\n",address_of($1));
                    codegen("ldc 1\n");
                    codegen("iadd\n");
                    codegen("istore %d\n",address_of($1));
            }
             else if(strcmp(type_of($1),"float")==0){
                    codegen("fload %d\n",address_of($1));
                    codegen("ldc 1.0\n");
                    codegen("fadd\n");
                    codegen("fstore %d\n",address_of($1));
            }
          printf("INC\n");
          }
    | id DEC     { 
        $$=$1;
        if(strcmp(type_of($1),"int")==0){
                    codegen("iload %d\n",address_of($1));
                    codegen("ldc 1\n");
                    codegen("isub\n");
                    codegen("istore %d\n",address_of($1));
        }
        else if(strcmp(type_of($1),"float")==0){
                    codegen("fload %d\n",address_of($1));
                    codegen("ldc 1.0\n");
                    codegen("fsub\n");
                    codegen("fstore %d\n",address_of($1));
            }
        printf("DEC\n");
        }
    ;
expression
    : expression OR andexpr {
        codegen("ior\n");
        if(strcmp($1,"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n",yylineno,$1);
        }
        if(strcmp($3,"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n",yylineno,$3);
        }
            printf("OR\n"); $$="bool";
        }
    | andexpr

    ;
andexpr
    : andexpr AND cmpexpr {
        codegen("iand\n");
        if(strcmp($1,"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n",yylineno,$1);
        }
        if(strcmp($3,"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n",yylineno,$3);
        }
        printf("AND\n"); $$="bool";
        }
    | cmpexpr
    ;
cmpexpr
    :  cmpexpr '>'  addexpr {
        printf("GTR\n"); $$="bool";
        if(strcmp($1,$3)==0){
            if(strcmp($1,"int")==0){
                codegen("isub\n");
                codegen("ifgt GTR_%d\n",tag);
                tag++;
                codegen("iconst_0\n");
                codegen("goto GTR_%d\n",tag);
                fprintf(fout,"GTR_%d:\n",tag-1);
                codegen("iconst_1\n");
                fprintf(fout,"GTR_%d:\n",tag);
                tag++;
            }
            else if(strcmp($1,"float")==0){
                codegen("fcmpl\n");
                codegen("ifgt GTR_%d\n",tag);
                tag++;
                codegen("iconst_0\n");
                codegen("goto GTR_%d\n",tag);
                fprintf(fout,"GTR_%d:\n",tag-1);
                codegen("iconst_1\n");
                fprintf(fout,"GTR_%d:\n",tag);
                tag++;
            }
        }

        }
    |  cmpexpr '<'  addexpr {
        printf("LSS\n"); $$="bool";
         if(strcmp($1,$3)==0){
                if(strcmp($1,"int")==0){
                    codegen("isub\n");
                    codegen("iflt LSS_%d\n",tag);
                    tag++;
                    codegen("iconst_0\n");
                    codegen("goto LSS_%d\n",tag);
                    fprintf(fout,"LSS_%d:\n",tag-1);
                    codegen("iconst_1\n");
                    fprintf(fout,"LSS_%d:\n",tag);
                    tag++;
                }
            }
        }
    |  cmpexpr LEQ  addexpr {
            printf("LEQ\n"); $$="bool";
            if(strcmp($1,$3)==0){
                if(strcmp($1,"int")==0){
                    codegen("isub\n");
                    codegen("ifle LEQ_%d\n",tag);
                    tag++;
                    codegen("iconst_0\n");
                    codegen("goto LEQ_%d\n",tag);
                    fprintf(fout,"LEQ_%d:\n",tag-1);
                    codegen("iconst_1\n");
                    fprintf(fout,"LEQ_%d:\n",tag);
                    tag++;
                }
            }
        }
    |  cmpexpr GEQ  addexpr {printf("GEQ\n"); $$="bool";}
    |  cmpexpr EQL  addexpr {

            printf("EQL\n"); $$="bool";
            if(strcmp($1,$3)==0){
                if(strcmp($1,"int")==0){
                    codegen("isub\n");
                    codegen("ifeq EQL_%d\n",tag);
                    tag++;
                    codegen("iconst_0\n");
                    codegen("goto EQL_%d\n",tag);
                    fprintf(fout,"EQL_%d:\n",tag-1);
                    codegen("iconst_1\n");
                    fprintf(fout,"EQL_%d:\n",tag);
                    tag++;
                }
            }
        }
    |  cmpexpr NEQ  addexpr {
        printf("NEQ\n"); $$="bool";
            if(strcmp($1,$3)==0){
                if(strcmp($1,"int")==0){
                    codegen("isub\n");
                    codegen("ifne NEQ_%d\n",tag);
                    tag++;
                    codegen("iconst_0\n");
                    codegen("goto NEQ_%d\n",tag);
                    fprintf(fout,"NEQ_%d:\n",tag-1);
                    codegen("iconst_1\n");
                    fprintf(fout,"NEQ_%d:\n",tag);
                    tag++;
                }
            }
        }
    | addexpr
    ;
addexpr
    :  addexpr '+' mulexpr    {
        if(strcmp($1,$3)==0){
            if(strcmp($1,"int")==0){
                codegen("iadd\n");   
            }
            else if(strcmp($1,"float")==0){
                codegen("fadd\n");   
            }
        }
        if(strcmp($1,$3)!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n",yylineno,$1,$3);      
             
        }
         printf("ADD\n"); $$=$3;
         }
    |   addexpr '-' mulexpr    { 
        if(strcmp($1,$3)==0){
            if(strcmp($1,"int")==0){
                codegen("isub\n");   
            }
            else if(strcmp($1,"float")==0){
                codegen("fsub\n");   
            }
        }
        if(strcmp($1,$3)!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n",yylineno,$1,$3);       
        }
        printf("SUB\n"); $$=$3;
        }
    | mulexpr {$$=$1;}
    ;
mulexpr
    : mulexpr '*' unaryexpr  {
        if(strcmp($1,$3)==0){
            if(strcmp($1,"int")==0){
                codegen("imul\n");   
            }
            else if(strcmp($1,"float")==0){
                codegen("fmul\n");   
            }
        }
         printf("MUL\n"); $$=$3;
         }
    | mulexpr '/' unaryexpr {
        if(strcmp($1,$3)==0){
            if(strcmp($1,"int")==0){
                codegen("idiv\n");   
            }
            else if(strcmp($1,"float")==0){
                codegen("fdiv\n");   
            }
        }   
        printf("QUO\n"); $$=$3;
        }
    | mulexpr '%' unaryexpr {
        if(strcmp($1,$3)==0){
            if(strcmp($1,"int")==0){
                codegen("irem\n");   
            }
            else if(strcmp($1,"float")==0){
                codegen("frem\n");   
            }
        }
        if(strcmp($1,"int")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator REM not defined on %s)\n",yylineno,$1);
        }
        if(strcmp($3,"int")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator REM not defined on %s)\n",yylineno,$3);
        }
         printf("REM\n"); $$=$3;
         }
    | unaryexpr {$$=$1;}
    ;
unaryexpr
    : '(' expression ')' {$$=$2;}
    | '-' unaryexpr {
        if(strcmp($2,"int")==0){
             codegen("ineg\n");
        }
        else if(strcmp($2,"float")==0){
             codegen("fneg\n");
        }       
        printf("NEG\n"); $$=$2
        ;}
    | '+' unaryexpr  {printf("POS\n"); $$=$2;}
    | NOT unaryexpr {
        codegen("ldc 1\n");
        codegen("ixor\n");
        printf("NOT\n");   $$="bool";
        }
    | id  arraysub {
            $$= eletype_of($1); 
           
            codegen("aload %d\n",address_of($1));
            codegen("iload 86\n");    
             if(strcmp(eletype_of($1),"int")==0){
                codegen("iaload\n");
            }
            else if(strcmp(eletype_of($1),"float")==0){
                codegen("faload\n");
            }
        }
    |  literal {
        $$=$1;

        }
    |  id {
        if(strcmp(type_of($1),"int")==0 ){
            codegen("iload %d\n", address_of($1));
        }
        else if(strcmp(type_of($1),"float")==0){
            codegen("fload %d\n", address_of($1));
        }
        else if(strcmp(type_of($1),"bool")==0){
            codegen("iload %d\n", address_of($1));
        }
        else if(strcmp(type_of($1),"string")==0){
            codegen("aload %d\n", address_of($1));
        }

        $$=type_of($1);
        }
    | '(' typename')' id  arraysub{
        // if(strcmp($2,"int")==0 && strcmp(eletype_of($4),"float")==0){
            
        //     printf("F to I\n");
        //     $$="int";
        // }
        // else  if(strcmp(eletype_of($4),"int")==0 && strcmp($2,"float")==0){
        //     printf("I to F\n");
        //     $$="float";
        // }
        if(strcmp($2,"int")==0 && strcmp(eletype_of($4),"float")==0){
            codegen("aload %d\n",address_of($4));
            codegen("iload 86\n");    
             if(strcmp(eletype_of($4),"int")==0){
                codegen("iaload\n");
            }
            else if(strcmp(eletype_of($4),"float")==0){
                codegen("faload\n");
            }
            codegen("f2i\n");
            $$="int";

        }
        else  if(strcmp(eletype_of($4),"int")==0 && strcmp($2,"float")==0){
            codegen("aload %d\n",address_of($4));
            codegen("iload 86\n");    
             if(strcmp(eletype_of($4),"int")==0){
                codegen("iaload\n");
            }
            else if(strcmp(eletype_of($4),"float")==0){
                codegen("faload\n");
            }
            codegen("i2f\n");
            $$="float";
        }
    
    }
      | '(' typename')' id {
        if(strcmp($2,"int")==0 && strcmp(type_of($4),"float")==0){
            
            printf("F to I\n");
            $$="int";
        }
        else  if(strcmp(type_of($4),"int")==0 && strcmp($2,"float")==0){
            printf("I to F\n");
            $$="float";
        }
        if(strcmp($2,"int")==0 && strcmp(type_of($4),"float")==0){
            codegen("fload %d\n", address_of($4));
            codegen("f2i\n");

        }
        else  if(strcmp(type_of($4),"int")==0 && strcmp($2,"float")==0){
            codegen("iload %d\n", address_of($4));
            codegen("i2f\n");

        }
    
    }
    | '(' typename')' literal {
        if(strcmp($2,"int")==0 && strcmp($4,"float")==0){
            printf("F to I\n");
            $$="int";
        }
        else  if(strcmp($4,"int")==0 && strcmp($2,"float")==0){
            printf("I to F\n");
            $$="float";
        }
        if(strcmp($2,"int")==0 && strcmp($4,"float")==0){

            codegen("f2i\n");

        }
        else  if(strcmp($4,"int")==0 && strcmp($2,"float")==0){
            codegen("i2f\n");
        }
    
    }
    
    ;
arraysub
    : '[' expression ']'{ codegen("istore 86\n");  $$="array";}




declarationstmt
    :   typename    IDENT  {
        if(!check_entry($2)){
            insert_variable($2,$1,yylineno,"-");
            printf("> Insert {%s} into symbol table (scope level: %d)\n",$2,level);
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,$2,line_of($2));
        }
         if(strcmp(type_of($2),"int")==0){
             codegen("ldc 0\n");
            codegen("istore %d\n",address_of($2));
        }
        else if(strcmp(type_of($2),"float")==0){
           codegen("ldc 0.0\n");
            codegen("fstore %d\n",address_of($2));
        }
         else if(strcmp(type_of($2),"string")==0){
            codegen("ldc \"\"\n");
            codegen("astore %d\n",address_of($2));
        }
         else if(strcmp(type_of($2),"bool")==0){
            codegen("ldc 0\n");
            codegen("istore %d\n",address_of($2));
        }
      
    }
    | typename IDENT  '=' expression {
        if(!check_entry($2)){
            insert_variable($2,$1,yylineno,"-");
            printf("> Insert {%s} into symbol table (scope level: %d)\n",$2,level);
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,$2,line_of($2));
        }
         if(strcmp(type_of($2),"int")==0){
            codegen("istore %d\n",address_of($2));
        }
        else if(strcmp(type_of($2),"float")==0){
            codegen("fstore %d\n",address_of($2));
        }
         else if(strcmp(type_of($2),"string")==0){
            codegen("astore %d\n",address_of($2));
        }
         else if(strcmp(type_of($2),"bool")==0){
            codegen("istore %d\n",address_of($2));
        }

    }
    | typename  IDENT '[' expression ']' {


        if(!check_entry($2)){
            insert_variable($2,"array",yylineno,$1);
            printf("> Insert {%s} into symbol table (scope level: %d)\n",$2,level);
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,$2,line_of($2));
        }
        if( strcmp($1,"int")==0){
            codegen("newarray int\n");
            codegen("astore %d\n",address_of($2));
        }
        else if(strcmp($1,"float")==0){
            codegen("newarray float\n");
            codegen("astore %d\n",address_of($2));
        }

    }
    | typename  IDENT '[' expression ']'  '=' expression {
        if(!check_entry($2)){
            insert_variable($2,"array",yylineno,$1);
            printf("> Insert {%s} into symbol table (scope level: %d)\n",$2,level);
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,$2,line_of($2));
        }

    }
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    codegen(".source hw3.j\n");
    codegen(".class public Main\n");
    codegen(".super java/lang/Object\n");
    codegen(".method public static main([Ljava/lang/String;)V\n");
    codegen(".limit stack 100\n");
    codegen(".limit locals 100\n");
    INDENT++;

    yyparse();

	printf("Total lines: %d\n", yylineno);

    /* Codegen end */
    codegen("return\n");
    INDENT--;
    codegen(".end method\n");
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }
    return 0;
}


    int address_of(char* name){
        if(sym_tb==NULL){
            return -1;
        }
        for(int i=level ; i>=0;i--){
            variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return trasverse->next->address;
                        }
                    trasverse=trasverse->next;
                }

            }
        }
        

        return -1;

}
bool check_entry(char* name){
        if(sym_tb==NULL){
            return 0;
        }

        variable *trasverse=&sym_tb[level];
        while(1){
            if (trasverse->next == NULL)
            {
                break;
            }
            else{
                if(!strcmp(trasverse->next->name,name)){
                        return 1;
                    }
                trasverse=trasverse->next;
            }
        }            
         

        return 0;
}

bool check_whole(char* name){
        if(sym_tb==NULL){
            return 0;
        }
         for(int i=level ; i>=0;i--){
             variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return 1;
                        }
                    trasverse=trasverse->next;
                }
            }            
         }

        return 0;
}
    int  line_of(char* name){
        
        if(sym_tb==NULL){
            return -1;
        }
         for(int i=level ; i>=0;i--){
             variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return trasverse->next->lineno;
                        }
                    trasverse=trasverse->next;
                }
            }            
         }

        return -1;

}
    char* type_of(char* name){
        
        if(sym_tb==NULL){
            return "sym_tb null";
        }
         for(int i=level ; i>=0;i--){
             variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return trasverse->next->type;
                        }
                    trasverse=trasverse->next;
                }
            }            
         }

        return "error";

}
    char* eletype_of(char* name){

        if(sym_tb==NULL){
            return "sym_tb null";
        }
         for(int i=level ; i>=0;i--){
            variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return trasverse->next->element_type;
                        }
                    trasverse=trasverse->next;
                }

            }
         }

        return "error";

}
     void create_symbol(){
        myIndex=0;
        if(sym_tb!=NULL){
            level++;
            sym_tb = (variable*)realloc(sym_tb,(level+1)*sizeof(variable));
            sym_tb[level].next=NULL;
        }
        else{
            level=0;
            sym_tb= (variable*)malloc((level+1)*sizeof(variable));
            sym_tb[level].next=NULL;
        }

        // if(level==0){
        //     level++;
        // }
    }

    void insert_variable( char* name , char*type,int lineno,char* element_type ){
        // printf("fuck you");
        if(sym_tb==NULL){
            // printf("fuck you");
            level=0;
            sym_tb= (variable*)malloc((level+1)*sizeof(variable));
            sym_tb[level].next=NULL;
        }
        variable *trasverse=&sym_tb[level];
        while(1){
            if (trasverse->next == NULL)
            {
                break;
            }
            else{
                trasverse=trasverse->next;
            }
        }
        trasverse->next=(variable*)malloc(sizeof(variable));
        variable*tmp=trasverse->next;
        tmp->next=NULL;
        tmp->index=myIndex;
        tmp->name=name;
        tmp->type=type;
        tmp->address=address;
        tmp->lineno=lineno;
        tmp->element_type=element_type;



        myIndex++;
        

        address++;
        

        // printf("> Insert {%s} into symbol table (scope level: %d)\n", name,level);
    }

    void dump_symbol(){
        printf("> Dump symbol table (scope level: %d)\n", level);
        printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno","Element type");
        variable *trasverse=&sym_tb[level];
        if(sym_tb==NULL){
            return;
        }
        while(1){
            if(trasverse->next==NULL){
                break;
            }
            printf("%-10d%-10s%-10s%-10d%-10d%s"
            ,trasverse->next->index
            ,trasverse->next->name
            ,trasverse->next->type
            ,trasverse->next->address
            ,trasverse->next->lineno,
            trasverse->next->element_type);

            variable *tmp=trasverse;
            trasverse=trasverse->next;
            if(tmp!=&sym_tb[level]){
                free(tmp);
            }
    
            if(trasverse==NULL){
                break;
            }
            else{
                printf("\n");
            }
        }
        
        level--;
        variable* stmp= realloc(sym_tb,(level+1)*sizeof(variable));
        if(stmp!=NULL){
            sym_tb=stmp;
        }
        if(level<0){
            sym_tb=NULL;
            level=0;
            return;
        }
        trasverse=&sym_tb[level];
        while(1){
            
            if(trasverse->next==NULL){
                if(trasverse!=&sym_tb[level]){
                    myIndex=trasverse->index+1;
                }
                else{
                    myIndex=0;
                }
                break;
            }
            else{
                trasverse=trasverse->next;
            }
        }

        
    }