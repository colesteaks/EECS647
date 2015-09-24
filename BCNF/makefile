bcnf: main.o
	g++ -g -std=c++11 main.o -o bcnf

main.o: main.cpp BCNFTester.h
	g++ -g -std=c++11 -c main.cpp

clean:
	rm -f bcnf main.o
