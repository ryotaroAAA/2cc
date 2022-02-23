CFLAGS=-std=c11 -g -static
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

2cc: $(OBJS)
	$(CC) -o 2cc $(OBJS) $(LDFLAGS)

$(OBJS): 2cc.h

test: 2cc
	./test.sh

clean:
	rm -f 2cc *.o *~ tmp*

.PHONY: test clean