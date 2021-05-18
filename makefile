testing: testing.cpp myList.o
	g++ -g -o testing testing.cpp myList.o

myList.o: list.h list.cpp
	g++ -g -o myList.o -c list.cpp