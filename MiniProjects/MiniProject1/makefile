# MiniProject_1 makefile
CC = g++
SHELL = /bin/bash
CFLAGS = -fPIC -g
LDFLAGS = -lm -lstats
LIBDIR = /home/thompsz/BIEN-4290/Labs/lab_1/ 
INCDIR = /home/thompsz/BIEN-4290/Labs/lab_1/ 

libstats.so:
	cd ~/BIEN-4290/Labs/lab_1/ && make libstats.so

airspeed: ~/BIEN-4290/MiniProjects/MiniProject1/thompsz_miniproject1.cpp
	make libstats.so
	$(CC) $(CFLAGS)	-I$(INCDIR) -o $@ $^ -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) $(LDFLAGS)