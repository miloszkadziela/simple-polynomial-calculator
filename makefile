all: testpoly 

testpoly: testpoly.o Poly.o
	g++ -g $^ -o $@

testpoly.o: testpoly.cpp 
	g++ -g -c -Wall -std=c++11 -pedantic $< -o $@

Poly.o: Poly.cpp Poly.h
	g++ -g -c -Wall -std=c++11 -pedantic $< -o $@

.PHONY: clean

clean:
	-rm Poly.o testpoly.o testpoly
