main : main.c phonenum.o
	gcc -o main main.c phonenum.o
clean :
	rm *.o main
