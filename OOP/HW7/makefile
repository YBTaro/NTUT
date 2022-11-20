.PHONY: directories clean stat

all: directories ut

CFLAGS = -std=c++11 -Wfatal-errors
SRC = src/algo.h src/cat.h src/dog.h src/pet.h
TEST = test/ut_algo.h test/ut_cat.h test/ut_dog.h

ut: test/ut_main.cpp $(SRC) $(TESTS)
	g++ $(CFLAGS) test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin

clean: directories
	rm -rf bin

stat:
	wc -l src/* test/*
