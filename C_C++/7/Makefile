all: main.o hashmap.o
	g++ -Wfatal-errors -o prog main.o hashmap.o
main.o: main.cpp hashmap.h
	g++ -Wfatal-errors -c main.cpp -o main.o
hashmap.o: hash_map.cpp hashmap.h
	g++ -Wfatal-errors -c hash_map.cpp -o hashmap.o
