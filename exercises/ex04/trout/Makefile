util.o: util.c util.h
	gcc -c util.c

trout.o: trout.c trout.h
	gcc -c trout.c

main.o: main.c trout.o trout.o
	gcc -c main.c

trout: main.c trout.o util.o
	gcc main.o trout.o util.o -o trout
