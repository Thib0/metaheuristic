CC = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++14 -o3
OBJ = main.o mheu.o
BIN = mheu
VPATH = src

$(BIN): $(OBJ)

clean:
	$(RM) $(OBJ) $(BIN)

.PHONY: clean
