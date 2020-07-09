all: app.exe test.exe

app.exe: main.o cdio.o functions.o
	gcc -o app.exe main.o cdio.o functions.o
test.exe: test.o functions.o cdio.o
	gcc -o test.exe test.o functions.o cdio.o
main.o: main.c
	gcc -std=c99 -Wall -Werror -c main.c
cdio.o: cdio.c
	gcc -std=c99 -Wall -Werror -c cdio.c
functions.o: functions.c
	gcc -std=c99 -Wall -Werror -c functions.c
test.o: test.c
	gcc -std=c99 -Wall -Werror -c test.c
clean:
	rm *.o *.exe
