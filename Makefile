main : main.c phonenum.o
	gcc -o $@ $^
clean :
	rm *.o main
