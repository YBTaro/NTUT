.PHONY: dirs clean stat

all: bin/unit
	
bin/unit: dirs test/ut_main.cpp test/ut_cat.h test/ut_toy.h src/cat.h src/toy.h
	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

dirs:
	mkdir -p bin

clean: dirs
	rm -rf bin

stat:
	wc src/* test/*
