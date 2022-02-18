CC = g++
SHELL = /bin/bash


mowin.o: mowin.cpp mowin.hpp
	g++ -c mowin.cpp

thehob.o: thehob.cpp thehob.hpp
	g++ -c thehob.cpp

base_classes: mowin.o thehob.o

# These are just running bash commands!
length_check: tthti.cpp mowin.o thehob.o
	g++ -o runtime tthti.cpp mowin.o thehob.o

finder:
	g++ -o runtime seememow.cpp mowin.cpp thehob.cpp

clean:
	rm runtime
	rm *.o

