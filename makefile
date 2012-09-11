CFLAGS = -lGL -lGLU -lglut
main: main.o llist.o
	gcc -o main main.o llist.o $(CFLAGS)

main.o: main.c
	gcc -c main.c

llist.o: llist.c llist.h
	gcc -c llist.c

clean:
	rm main *.o
