all: app.exe test.exe

app.exe: main.o cdio.o func.o
	gcc -o app.exe main.o cdio.o func.o
test.exe: test.o cdio.o func.o
	gcc -o test.exe test.o cdio.o func.o
main.o: main.c
	gcc -std=c99 -Wall -Werror -c main.c
test.o: test.c
	gcc -std=c99 -Wall -Werror -c test.c
cdio.o: cdio.c
	gcc -std=c99 -Wall -Werror -c cdio.c
func.o: func.c
	gcc -std=c99 -Wall -Werror -c func.c
clean:
	rm *.o *.exe

