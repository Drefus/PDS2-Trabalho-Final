CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/game.o $(OBJ)/gameStatus.o $(OBJ)/player.o $(OBJ)/playersManagement.o $(OBJ)/stringUtils.o $(OBJ)/playersMenu.o $(OBJ)/lig4.o
HDRS = $(INC)/game.hpp $(INC)/gameStatus.hpp $(INC)/player.hpp $(INC)/playersManagement.hpp $(INC)/stringUtils.hpp $(INC)/playersMenu.hpp $(INC)/lig4.hpp
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

$(OBJ)/lig4.o:$(HDRS) $(SRC)/lig4.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lig4.o $(SRC)/lig4.cpp

$(OBJ)/playersMenu.o: $(HDRS) $(SRC)/playersMenu.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/playersMenu.o $(SRC)/playersMenu.cpp
	
$(OBJ)/playersManagement.o: $(HDRS) $(SRC)/playersManagement.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/playersManagement.o $(SRC)/playersManagement.cpp

$(OBJ)/game.o: $(HDRS) $(SRC)/game.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/game.o $(SRC)/game.cpp

$(OBJ)/player.o: $(HDRS) $(SRC)/player.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/player.o $(SRC)/player.cpp

$(OBJ)/gameStatus.o: $(HDRS) $(SRC)/gamestatus.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/gamestatus.o $(SRC)/gamestatus.cpp

$(OBJ)/stringUtils.o: $(HDRS) $(SRC)/stringUtils.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/stringUtils.o $(SRC)/stringUtils.cpp


	
clean:
	rm -f $(BIN)/*.out $(EXE) $(OBJS) gmon.out