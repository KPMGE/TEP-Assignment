OBJ          = ./obj
INCLUDE      = ./include
SRC          = ./src
BIN          = ./bin
CC           = gcc 
FLAGS        = -lm
NAME_PROGRAM = test.exe

all: libed create

libed: rational-numbers.o main.o

%.o: $(SRC)/%.c 
	@$(CC) -c $< -I $(INCLUDE) -o $(OBJ)/$@ 

create: 	
	@$(CC) -o $(BIN)/$(NAME_PROGRAM) $(OBJ)/*.o $(FLAGS)

run: 
	@clear
	@./$(BIN)/$(NAME_PROGRAM)
	@echo "\n\n\n"
	@cowsay "You're the best programmer of the intire world bro!"

clean:
	@rm $(OBJ)/*.o
	@rm $(BIN)/$(NAME_PROGRAM)
	@rm *.csv
