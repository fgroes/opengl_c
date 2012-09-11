CFLAGS = -lGL -lGLU -lglut
MAIN = main.o graphics.o keyboard.o llist.o 

main: $(MAIN)
	gcc -o main $(MAIN) $(CFLAGS)

main.o: main.c
	gcc -c main.c

graphics.o: graphics.c graphics.h
	gcc -c graphics.c

keyboard.o: keyboard.c keyboard.h
	gcc -c keyboard.c

llist.o: llist.c llist.h
	gcc -c llist.c

clean:
	rm main *.o
