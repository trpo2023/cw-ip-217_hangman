CXX=g++
CFLAGS= -I src/
HANGMAN_SRC = src/main/
HANGMANFUNC_SRC = src/func/
HANGMAN_OBJ = obj/src/hangman/
HANGMANFUNC_OBJ = obj/src/func/
HANGMAN_BIN = bin/
SRC = src/
TEST = test/
HANGMAN_TEST_OBJ = obj/hangman_test/
THIRDPARTY = thirdparty/

.PHONY: hangman

$(HANGMAN_BIN)main: $(HANGMAN_OBJ)main.o $(HANGMANFUNC_OBJ)game.o $(HANGMANFUNC_OBJ)term.o
	$(CXX) $(CFLAGS) $^ -o $@
$(HANGMAN_OBJ)main.o: $(HANGMAN_SRC)main.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(HANGMANFUNC_OBJ)game.o: $(HANGMANFUNC_SRC)game.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@
$(HANGMANFUNC_OBJ)term.o: $(HANGMANFUNC_SRC)term.cpp
	$(CXX) -c -Wall -std=c++11 $(CFLAGS) $< -o $@

.PHONY: test

test: $(HANGMAN_BIN)test.out
	./$<

$(HANGMAN_BIN)test.out: $(HANGMAN_TEST_OBJ)ctest.o $(HANGMAN_TEST_OBJ)main.o $(HANGMAN_TEST_OBJ)testlib.a 
	$(CXX) -I thirdparty/ $(CFLAGS) -o $@ $^
$(HANGMAN_TEST_OBJ)ctest.o: $(TEST)ctest.cpp
	$(CXX) -c -I thirdparty/ $(CFLAGS) -o $@ $^
$(HANGMAN_TEST_OBJ)main.o: $(TEST)main.cpp
	$(CXX) -c -I thirdparty/ $(CFLAGS) -o $@ $^
$(HANGMAN_TEST_OBJ)testlib.a: $(HANGMAN_TEST_OBJ)game.o $(HANGMAN_TEST_OBJ)term.o 
	ar rcs $@ $^
$(HANGMAN_TEST_OBJ)game.o: $(HANGMANFUNC_SRC)game.cpp
	$(CXX) -c -I thirdparty/ $(CFLAGS) -o $@ $^
$(HANGMAN_TEST_OBJ)term.o: $(HANGMANFUNC_SRC)term.cpp
	$(CXX) -c -I thirdparty/ $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -rf $(HANGMAN_BIN)*.out
	rm -rf $(HANGMAN_BIN)*
	rm -rf $(HANGMAN_OBJ)*.o
	rm -rf $(HANGMANFUNC_OBJ)*.o
	rm -rf $(HANGMANFUNC_OBJ)*.a
	rm -rf $(HANGMAN_TEST_OBJ)*.o
	rm -rf $(HANGMAN_TEST_OBJ)*.a

.PHONY: format

CPPS := $(shell find . -type f -name '*.cpp')
HS := $(shell find . -type f -name '*.h')

format:
	clang-format -i $(CPPS) $(HS)
