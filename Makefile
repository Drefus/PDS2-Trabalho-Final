CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o 
CFLAGS = -Wall -c -g -I$(INC)

EXE = $(BIN)/main

 
.PHONY: all debug clean 

all: $(BIN)/tp.out

debug: $(BIN)/tp_teste.out

$(BIN)/tp_teste.out: $(OBJS)
	$(CC) -o $(BIN)/tp_teste.out $(OBJS) $(LIBS)

$(BIN)/tp.out: $(OBJS)
	$(CC) -o $(BIN)/tp.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp


	
clean:
	rm -f $(BIN)/*.out $(EXE) $(OBJS) gmon.out