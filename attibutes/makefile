CC := g++
CPPFLAGS := -std=c++2a
objects := attributes.o
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
