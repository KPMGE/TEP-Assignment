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
	$(CC) -c $< -I $(INCLUDE) -o $(OBJ)/$@ 

create: 	
	$(CC) -o $(BIN)/$(NAME_PROGRAM) $(OBJ)/*.o $(FLAGS)

run: 
	./$(BIN)/$(NAME_PROGRAM)

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/$(NAME_PROGRAM)
