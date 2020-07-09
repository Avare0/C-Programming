all: test.exe

test.exe: test.o func.o
	gcc -o test.exe test.o func.o
test.o: test.c
	gcc -std=c99 -Wall -Werror -c test.c
func.o: func.c
	gcc -std=c99 -Wall -Werror -c func.c
clean:
	rm *.o *.exe

