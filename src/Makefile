
CFLAGS=-g -O3

all: tokenizer

tokenizer.o: tokenizer.h

tokenizer: tokenizer.o
	cc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o tokenizer
