#lab_1 stats makefile
CC = g++
SHELL = /bin/bash
CFLAGS = -fPIC -g

thompsz_stats.o: thompsz_stats.cpp thompsz_stats.hpp
	$(CC) $(CLFLAGS) -o $@ -lm

libstats.so: thompsz_stats.cpp thompsz_stats.hpp
	$(CC) -shared $^ -o $@

clean: libstats.so thompsz_stats.o
	rm -f *.o
	rm -f *.so