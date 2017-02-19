all: main.o bmp.o
	gcc main.o bmp.o -o main

bmp.o: bmp.c
	gcc -c bmp.c -o bmp.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm *.o -f
