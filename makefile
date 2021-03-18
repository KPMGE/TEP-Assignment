OBJ          = ./obj
INCLUDE      = ./include
SRC          = ./src
BIN          = ./bin
CC           = gcc 
FLAGS        = -lm -Wall -O3 -std=c99
NAME_PROGRAM = program.exe

all: libed create

libed: $(OBJ)/rational-numbers.o $(OBJ)/main.o

create: $(BIN)/$(NAME_PROGRAM) 	

# rule for libed
$(OBJ)/%.o: $(SRC)/%.c  
	@$(CC) -c $< -I $(INCLUDE) -o $@ 

# rule for create
$(BIN)/%: 
	@$(CC) $< $(OBJ)/*.o -I $(INCLUDE) -o $@ $(FLAGS)

run: 
	@clear
	@./$(BIN)/$(NAME_PROGRAM)
	@echo "\n\n\n"
	@cowsay "You're the best programmer of the intire world bro!"

clean:
	@rm $(OBJ)/*.o
	@rm $(BIN)/$(NAME_PROGRAM)
	@rm *.csv
