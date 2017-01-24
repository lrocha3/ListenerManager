CC = g++

BIN = ListenerManager.exe

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib
LIBS_INC ?=


#Ao definir o SRC e colocar a var
#OBJ apenas com os ficheiros
#que o SRC tem a compilação
#só vai criar os objectos que são
#necessários. Ficheiros dummy não
#são adicionados.

SRC = $(SRC_DIR)/main.cpp   \
	$(SRC_DIR)/Queue.cpp	\
	$(SRC_DIR)/Listener.cpp	\
	$(SRC_DIR)/Phone.cpp

OBJ  = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
#$(info $$OBJ is [${OBJ}]) to print var


INCFLAGS = -I $(INC_DIR)


DEBUG = -g

#C++ Standard
CPPSTD = -std=c++11

#CFLAGS --> Creation of objects
CFLAGS = -Wall -c $(DEBUG) $(CPPSTD)
#LDFLAGS --> Linking Objects
LDFLAGS = -Wall $(DEBUG)

LDLIBS =?
#? == nothing still

all: prepare_environment $(BIN_DIR)/$(BIN) 

prepare_environment:
	mkdir $(OBJ_DIR) -p
	mkdir $(BIN_DIR) -p

$(BIN_DIR)/$(BIN): $(OBJ)
	$(info Linking objs to bin.)
	$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp


$(OBJ): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(info Creating objs.)
	$(CC) $(INCFLAGS) $(CFLAGS) $< -o $@

clean:
	$(info Deleting objs and bin.)
	$(RM) $(OBJ) $(BIN_DIR)/$(BIN)

execute:
	@if test -f $(BIN_DIR)/$(BIN); then \
		./$(BIN_DIR)/$(BIN); \
	else \
		echo "No binary file!"; \
	fi

#if there is a file in the
#makefile directory with
#the name all, clean or execute
#the make all or make clean or make execute
#will be guaranted to be executed.

.PHONY: all clean execute
