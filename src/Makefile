# makefile for uniqueness track utilities
CC=clang++
VPATH=SeqReader gzstream .
INC=-ISeqReader/ -Igzstream
#LIB=-LSeqReader/ -Lgzstream
LDFLAGS=-lz -lm
CFLAGS=-Wall -pedantic -O0 -g

HEADERS=DNAString.h Quality.h SeqReader.h Util.h gzstream.h
OBJS=DNAString.o Quality.o SeqReader.o Util.o gzstream.o splitfa.o

splitfa: $(OBJS) splitfa.o
	$(CC) $(CFLAGS) $(LDFLAGS) $(INC) $(LIB) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(INC) -c $<

clean:
	rm -f SeqReader/*.o gzstream/*o split_fa *.o
