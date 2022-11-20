.PHONY: directories clean stat

all: directories bin/ut_all

CFLAGS = -std=c++11 -Wfatal-errors
HEADERS = test/ut_term.h test/ut_polynomial.h
TESTS = src/term.h src/polynomial.h

bin/ut_all: test/ut_main.cpp $(HEADERS) $(TESTS)
	g++ $(CFLAGS) test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean: directories
	rm -rf bin

stat:
	wc src/* test/*
