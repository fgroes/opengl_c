CFLAGS = -lGL -lGLU -lglut
MAIN = main.o graphics.o keyboard.o llist.o load_geo_obj.o math_adv.o

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

load_geo_obj.o: load_geo_obj.c load_geo_obj.h
	gcc -c load_geo_obj.c

math_adv.o: math_adv.c math_adv.h
	gcc -c math_adv.c

clean:
	rm main *.o
