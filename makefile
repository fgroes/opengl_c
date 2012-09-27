CFLAGS = -lGL -lGLU -lglut -lm -lSOIL
MAIN = main.o graphics.o keyboard.o mouse.o llist.o geometry.o texture.o init_geo.o cube.o math_adv.o

main: $(MAIN)
	gcc -o main $(MAIN) $(CFLAGS)

main.o: main.c
	gcc -c main.c

graphics.o: graphics.c graphics.h
	gcc -c graphics.c

keyboard.o: keyboard.c keyboard.h
	gcc -c keyboard.c

mouse.o: mouse.c mouse.h
	gcc -c mouse.c

llist.o: llist.c llist.h
	gcc -c llist.c

geometry.o: geometry.c geometry.h
	gcc -c geometry.c

texture.o: texture.c texture.h
	gcc -c texture.c


init_geo.o: init_geo.c init_geo.h
	gcc -c init_geo.c

cube.o: cube.c cube.h
	gcc -c cube.c

math_adv.o: math_adv.c math_adv.h
	gcc -c math_adv.c

clean:
	rm main *.o
