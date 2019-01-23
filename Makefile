all: all_tests

mkdir:
	mkdir build -p

tests_strstr: mkdir
	g++ -std=c++11 -Wall -Werror -o build/tests_strstr test_strstr.cpp -lcppunit

all_tests: tests_strstr

clean: rm -rf build