#lab_1 stats makefile
CC = g++
SHELL = /bin/bash
CFLAGS = -fPIC -g

thompsz_stats.o: ~/BIEN-4290/Labs/lab_1/thompsz_stats.cpp
	$(CC) $(CLFLAGS) -o $@ -lm

libstats.so: thompsz_stats.o
	$(CC) -shared $^ -o $@

clean: libstats.so thompsz_stats.o
	rm -f *.o
	rm -f *.so