CFLAGS = -lGL -lGLU -lglut
main: main.o
	gcc -o main main.o $(CFLAGS)

main.o: main.c
	gcc -c main.c

clean:
	rm main *.o
