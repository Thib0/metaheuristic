CC = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++14 -g
OBJ = main.o mheu.o
BIN = mheu

$(BIN): $(OBJ)

clean:
	$(RM) $(OBJ) $(BIN)

.PHONY: clean
