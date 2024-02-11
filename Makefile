CC=g++
FLAGS=-std=c++17 -Wall -Wextra -Werror
MODULES=matrix_func.cpp matrix_init.cpp matrix_operators.cpp matrix_support.cpp
MODULES_O=$(MODULES:.cpp=.o)
SRC_DIR=modules
TEST=tests/matrix_tests.cpp
LIB_NAME=lib_matrix.a

all: clean $(LIB_NAME) test

$(LIB_NAME): $(MODULES_O)
	ar rc $(LIB_NAME) $(MODULES_O)
	ranlib $(LIB_NAME)

%.o: $(SRC_DIR)/%.cpp
	$(CC) $(FLAGS) -c $< -o $@

test: clean $(LIB_NAME)
	$(CC) $(FLAGS) -fprofile-arcs -ftest-coverage $(TEST) $(LIB_NAME) -lgtest -lgtest_main -o test
	./test
gcov_flag:
	$(eval FLAGS += -fprofile-arcs -ftest-coverage)

gcov_report: gcov_flag test
	gcov --no-output $(TEST)
	lcov --no-external --capture --directory . --output-file coverage.info
	genhtml coverage.info -o report


clean:
	rm -f *.o *.a test *.gcda *.gcno *.info
	rm -rf report

Key Changes: