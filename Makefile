CC = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++14 -o3
OBJ = main.o mheu.o
OBJ2 = main.o function.o
BIN = mheu
BIN2 = essaim
VPATH = src

$(BIN): $(OBJ)

$(BIN2): $(OBJ2)

clean:
	$(RM) $(OBJ) $(BIN)

.PHONY: clean
