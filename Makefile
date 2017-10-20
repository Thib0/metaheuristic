CC = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++14 -g#-O3 -DNDEBUG
OBJ = main.o mheu.o
OBJS = function.o particle.o swarm.o
BIN = mheu
VPATH = src

##################################################################
OBJS = function.o particle.o swarm.o essaim.o
TARGET = essaim

$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)


essaim: $(OBJS)

$(BIN): $(OBJ)

clean:
	$(RM) $(OBJ) $(BIN) $(OBJS) $(BIN2)

.PHONY: clean
