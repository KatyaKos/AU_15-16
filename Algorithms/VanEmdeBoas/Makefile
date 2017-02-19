all: main.o binary.o boas.o
	g++ -std=c++11 main.o binary.o boas.o -o main

boas.o: boas.cpp
	g++ -std=c++11 -c boas.cpp -o boas.o

binary.o: binary.cpp
	g++ -std=c++11 -c binary.cpp -o binary.o

main.o: main.cpp 
	g++ -std=c++11 -c main.cpp -o main.o

pq_bin_boas: pq_bin_boas.o
	g++ -std=c++11 pq_bin_boas.o -o pq_bin_boas

pq_bin_boas.o: pq_bin_boas.cpp
	g++ -std=c++11 -c pq_bin_boas.cpp -o pq_bin_boas.o

boas_test: boas_test.o
	g++ -std=c++11 boas_test.o -o boas_test

boas_test.o: boas_test.cpp
	g++ -std=c++11 -c boas_test.cpp -o boas_test.o

clean:
	rm *.o -f