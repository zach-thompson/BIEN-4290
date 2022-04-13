# MiniProject_1 makefile
CC = g++
SHELL = /bin/bash
CFLAGS = -fPIC -g
LDFLAGS = -lm -lstats
LIBDIR = /home/thompsz/BIEN-4290/Labs/lab_1/ 
INCDIR = /home/thompsz/BIEN-4290/Labs/lab_1/ 

libstats.so:
	cd "/home/thompsz/BIEN-4290/Labs/lab_1/" && make libstats.so

airspeed: thompsz_miniproject1.cpp
	make libstats.so
	$(CC) $(CFLAGS)	-I$(INCDIR) -o $@ $^ -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) $(LDFLAGS)