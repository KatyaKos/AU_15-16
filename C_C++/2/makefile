all: main.o str_func.o
	g++ -o prog main.o str_func.o
main.o: main.cpp str_func.h
	g++ -c main.cpp -o main.o
str_func.o: str_func.cpp str_func.h
	g++ -c str_func.cpp -o str_func.o
clean:
	rm main.o
	rm str_func.o
