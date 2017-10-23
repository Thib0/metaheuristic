CC = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++14 -g#-O3 -DNDEBUG
OBJ = main.o mheu.o
OBJS = function.o particle.o swarm.o essaim.o
BIN = mheu
BIN2 = swarm
VPATH = src

all: $(BIN) $(BIN2)

$(BIN2) : $(OBJS)
	$(CC) -o $(BIN2) $(OBJS)

$(BIN): $(OBJ)

clean:
	$(RM) $(OBJ) $(BIN) $(OBJS) $(BIN2)

.PHONY: clean
