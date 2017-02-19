all: huffman

bin/main.o: src/main.cpp src/huffman.h
	g++ -std=c++11 -c src/main.cpp -o bin/main.o
bin/huffman.o: src/huffman.cpp src/huffman.h
	g++ -std=c++11 -c src/huffman.cpp -o bin/huffman.o
huffman: bin/main.o bin/huffman.o
	g++ -std=c++11 bin/main.o bin/huffman.o -o huffman

test: testing

bin/autotest.o: test/autotest.cpp test/autotest.h
	g++ -std=c++11 -c test/autotest.cpp -o bin/autotest.o
bin/huffman_test.o: test/huffman_test.cpp test/huffman_test.h
	g++ -std=c++11 -c test/huffman_test.cpp -o bin/huffman_test.o
bin/test.o: test/test.cpp
	g++ -std=c++11 -c test/test.cpp -o bin/test.o
testing: bin/test.o bin/huffman_test.o bin/autotest.o bin/huffman.o
	g++ -std=c++11 bin/test.o bin/huffman_test.o bin/autotest.o bin/huffman.o -o testing
clean:
	rm bin/*

$(shell mkdir -p bin)