PROBLEM = 0008_sort
SOLUTION = merging

INCLUDE = include
SRC = src
BIN = bin
PROBLEMS = problems

CC = g++
CFLAGS = -Wall -g -I$(INCLUDE)

TEST_INPUT_FILE_NAME = test.in
TEST_OUTPUT_FILE_NAME = test.out

SOURCES = $(wildcard $(SRC)/$(PROBLEM)/*.cpp)
APPS = $(patsubst $(SRC)/$(PROBLEM)/%.cpp,$(BIN)/%,$(SOURCES))

PERFORMANCE_TEST_COUNT = 10
PERFORMANCE_TEST_INPUT_FILES = $(wildcard $(PROBLEMS)/$(PROBLEM)/performance_test_*.in)

all: $(APPS) judge performance_test show_performance_test_result

clean:
	rm -rf $(BIN)/*

run_test: all
	cp $(PROBLEMS)/$(PROBLEM)/$(TEST_INPUT_FILE_NAME) $(BIN)/
	$(BIN)/$(SOLUTION) | $(BIN)/judge $(PROBLEMS)/$(PROBLEM)/$(TEST_OUTPUT_FILE_NAME) $(BIN)/$(TEST_OUTPUT_FILE_NAME)

run_performance_test: all
	$(BIN)/performance_test $(PERFORMANCE_TEST_COUNT) $(words $(APPS)) $(words $(PERFORMANCE_TEST_INPUT_FILES)) $(APPS) $(PERFORMANCE_TEST_INPUT_FILES)
	$(BIN)/show_performance_test_result

$(APPS): $(SOURCES) run_problem.o
	$(CC) $(CFLAGS) -o $@ $(patsubst $(BIN)/%,$(SRC)/$(PROBLEM)/%.cpp,$@)  $(BIN)/run_problem.o

run_problem.o: $(SRC)/run_problem.cpp
	$(CC) $(CFLAGS) -o $(BIN)/run_problem.o -c $(SRC)/run_problem.cpp

judge: $(SRC)/judge.cpp
	$(CC) $(CFLAGS) -o $(BIN)/judge $(SRC)/judge.cpp

performance_test: $(SRC)/performance_test.cpp
	$(CC) $(CFLAGS) -o $(BIN)/performance_test $(SRC)/performance_test.cpp

show_performance_test_result: $(SRC)/show_performance_test_result.cpp
	$(CC) $(CFLAGS) -o $(BIN)/show_performance_test_result $(SRC)/show_performance_test_result.cpp

