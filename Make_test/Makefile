out : main.o
	gcc  -o out  main.o
main.o :
	gcc -c -g -D HDEBUG main.c
.PHONY : clean
clean :
	rm *.o out
