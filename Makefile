CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o
HDRS = $(INC)/board.hpp
CFLAGS = -Wall -c -g -I$(INC)

EXE = $(BIN)/main

 
.PHONY: all debug clean 

all: $(BIN)/tp.out

debug: $(BIN)/tp_teste.out

$(BIN)/tp_teste.out: $(OBJS)
	$(CC) -o $(BIN)/tp_teste.out $(OBJS) $(LIBS)

$(BIN)/tp.out: $(OBJS)
	$(CC) -o $(BIN)/tp.out $(OBJS) $(LIBS)

$(OBJ)/main.o:$(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/board.o: $(HDRS) $(SRC)/board.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/board.o $(SRC)/board.cpp


	
clean:
	rm -f $(BIN)/*.out $(EXE) $(OBJS) gmon.out