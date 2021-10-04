.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
	ldc 0
	istore 0
	ldc 0
	istore 0
Condition0:
	iload 0
	ldc 10
	isub
	iflt LSS_0
	iconst_0
	goto LSS_1
LSS_0:
	iconst_1
LSS_1:
	ifeq For_End0
	goto For_Body0
Arith0:
	iload 0
	ldc 1
	iadd
	istore 0
	goto Condition0
For_Body0:
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	goto Arith0
For_End0:
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 1
	istore 0
While_begin_0 :
	iload 0
	ldc 0
	isub
	ifgt GTR_2
	iconst_0
	goto GTR_3
GTR_2:
	iconst_1
GTR_3:
	ifeq While_exit_0
	iload 0
	ldc 1
	isub
	istore 0
	ldc 3
	newarray int
	astore 1
	ldc 0
	ldc 1
	ldc 21
	iadd
	istore 82
	istore 83
	aload 1
	iload 83
	iload 82
	iastore
	ldc 1
	ldc 0
	istore 86
	aload 1
	iload 86
	iaload
	ldc 1
	isub
	istore 82
	istore 83
	aload 1
	iload 83
	iload 82
	iastore
	ldc 2
	ldc 1
	istore 86
	aload 1
	iload 86
	iaload
	ldc 3
	idiv
	istore 82
	istore 83
	aload 1
	iload 83
	iload 82
	iastore
	ldc 2
	istore 86
	aload 1
	iload 86
	iaload
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 3
	ldc 4
	ldc 5
	ldc 8
	ineg
	iadd
	imul
	isub
	ldc 10
	ldc 7
	idiv
	isub
	ldc 4
	ineg
	ldc 3
	irem
	isub
	ifgt GTR_4
	iconst_0
	goto GTR_5
GTR_4:
	iconst_1
GTR_5:
	ldc 1
	ldc 1
	ixor
	ldc 0
	ldc 1
	ixor
	ldc 1
	ixor
	iand
	ior
	ifne BOOL_6
	ldc "false"
	goto BOOL_7
BOOL_6:
	ldc "true"
BOOL_7:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 3
	newarray float
	astore 2
	ldc 0
	ldc 1.100000
	ldc 2.100000
	fadd
	fstore 82
	istore 83
	aload 2
	iload 83
	fload 82
	fastore
	ldc 0
	istore 86
	aload 2
	iload 86
	faload
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	goto While_begin_0
While_exit_0:
	ldc 0
	istore 3
	ldc 10
	iload 3
	iadd
	istore 3
While_begin_10 :
	iload 3
	ldc 0
	isub
	ifgt GTR_8
	iconst_0
	goto GTR_9
GTR_8:
	iconst_1
GTR_9:
	ifeq While_exit_10
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	ldc 1
	isub
	istore 3
	iload 3
	ldc 0
	isub
	ifne NEQ_10
	iconst_0
	goto NEQ_11
NEQ_10:
	iconst_1
NEQ_11:
	ifeq IF_FALSE_2
	ldc 3.140000
	fstore 4
	fload 4
	f2i
	iload 3
	iadd
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	goto IF_EXIT_2
IF_FALSE_2:
	ldc 6.600000
	fstore 5
	ldc "If x == "
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	ldc 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	fload 5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(F)V
IF_EXIT_2:
	ldc 1
	istore 6
While_begin_11 :
	iload 6
	ldc 3
	isub
	ifle LEQ_12
	iconst_0
	goto LEQ_13
LEQ_12:
	iconst_1
LEQ_13:
	ifeq While_exit_11
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "*"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "="
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 3
	iload 6
	imul
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(I)V
	ldc "\t"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	iload 6
	ldc 1
	iadd
	istore 6
	goto While_begin_11
While_exit_11:
	ldc "\n"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
	goto While_begin_10
While_exit_10:
	return
.end method
