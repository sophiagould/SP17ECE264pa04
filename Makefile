CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
COVFLAGS = -fprofile-arcs -ftest-coverage
PROFFLAG = -pg
FLAGS = -DRUN_INTEGRATE -DTEST_INTEGRATE
GCC = gcc $(FLAGS) $(CFLAGS) $(COVFLAGS) $(PROFLAG)
OBJS = pa04.o answer04.o func1.o func2.o func3.o func4.o func5.o

pa04.o: pa04.c
		$(GCC) -c pa04.c
answer04.o: answer04.c
		$(GCC) -c answer04.c $(FLAGS) 
func1.o: func1.c
		$(GCC) -c func1.c
func2.o: func2.c
		$(GCC) -c func2.c
func3.o: func3.c
		$(GCC) -c func3.c
func4.o: func4.c
		$(GCC) -c func4.c
func5.o: func5.c
		$(GCC) -c func5.c


pa04: $(OBJS) 
		$(GCC) $(OBJS) -o pa04 -lm

testall: pa04
		echo "output_test1"
		./pa04 testdir/test1 output_test1
		echo "output_test2"
		./pa04 testdir/test2 output_test2
		echo "output_test3"
		./pa04 testdir/test3 output_test3
		echo "output_test4"
		./pa04 testdir/test4 output_test4
		echo "output_test5"
		./pa04 testdir/test5 output_test5
clean:
	/bin/rm -f input*
	/bin/rm -f *.o
	/bin/rm -f testgen 
	/bin/rm -f *.gcda *.gcno gmon.out *gcov
	/bin/rm -f pa04 pa04.prof


