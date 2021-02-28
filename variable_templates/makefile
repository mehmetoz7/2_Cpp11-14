CC := g++
CPPFLAGS := -std=c++14
objects := variable.o
libs :=

exec: $(objects)
	$(CC) $^ $(libs) -o $@

%.o: %.c
	$(CC) $(CPPFLAGS) -c $<
	
.PHONY: clean help
clean:
	rm -f exec $(objects)

help:
	@echo "make"
	@echo "make clean"
