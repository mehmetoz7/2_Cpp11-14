CC := g++
CPPFLAGS := -std=c++14
objects := auto.o
libs :=

auto: $(objects)
	$(CC) $^ $(libs) -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) -c $<
	
.PHONY: clean help
clean:
	rm auto *.o

help:
	@echo "make"
	@echo "make clean"
