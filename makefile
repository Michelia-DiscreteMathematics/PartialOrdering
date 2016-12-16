install: PartialOrdering

PartialOrdering: Poset.o main.o
	g++ -g -o PartialOrdering Poset.o main.o -std=c++11

Poset.o: Poset.h Poset.cpp
	g++ -g -c -o Poset.o Poset.cpp -std=c++11

main.o: main.cpp
	g++ -g -c -o main.o main.cpp -std=c++11

clean:
	rm Poset.o main.o PartialOrdering
