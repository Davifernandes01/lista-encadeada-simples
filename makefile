APPS = ./apps
BIN = ./bin
INCLUDE = ./include
LIB = ./lib
OBJ = ./obj
SRC = ./src

FLAGS = -O3 -Wall
LIBS = -lm -led -L $(LIB)

all: libED myapps



libED: \
	$(OBJ)/linkedList.o
	ar -rcs $(LIB)/libed.a $(OBJ)/*.o

	

$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	gcc $(FLAGS) -c $< -I $(INCLUDE) -o $@

# ... (outras definições no Makefile)

$(BIN)/%: $(APPS)/%.c
	gcc $(FLAGS) $< $(LIBS) -I $(INCLUDE) -o $@


# ... (outras definições no Makefile)

# ... (outras definições no Makefile)

myapps: $(BIN)/app

$(BIN)/app: $(APPS)/linked_list.c $(OBJ)/linkedList.o
	gcc $(FLAGS) $^ $(LIBS) -I $(INCLUDE) -o $@

# ... (outras definições no Makefile)





run:
	$(BIN)/app


clean:
	rm -rf $(BIN)/* $(LIB)/* $(OBJ)/*

clean_apps:
	rm -rf $(BIN)/*


debug:
	@echo $(BIN) $(APPS) $(OBJ) $(INCLUDE)  # Exibe os valores das variáveis para debug
