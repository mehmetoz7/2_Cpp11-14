all: exec

exec: auto.o
	g++ auto.o -o auto

auto.o: auto.cc
	g++ -std=c++14 -c auto.cc
	
.PHONY: clean help
clean:
	rm auto *.o

help:
	@echo "make"
	@echo "make clean"
