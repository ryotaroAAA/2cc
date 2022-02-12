CFLAGS=-std=c11 -g -static

2cc: 2cc.c11

test: 2cc
./test.sh

clean:
rm -f 2cc *.o *~ tmp*

.PHONY: test clean