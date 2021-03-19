OBJ          = ./obj
INCLUDE      = ./include
SRC          = ./src
BIN          = ./bin

CC           = gcc 
FLAGS        = -lm -Wall -O3 -std=c99

NAME_PROGRAM = program.exe



run: all
	@./${BIN}/${NAME_PROGRAM}
	@ echo "\n\n\n"
	@ cowsay "You're the best programmer of the intire world bro!"


valgrind: all
	@ clear
	@ valgrind ./${BIN}/${NAME_PROGRAM}
	@ echo "\n\n"


all: directories libed create 
	@ echo " \033[1;32m  Done!  \033[0m "
	@ echo ''


create: ${BIN}/${NAME_PROGRAM}


directories:
	@ mkdir ${OBJ}
	@ mkdir ${BIN}


libed: \
	${OBJ}/rational-numbers.o\
	${OBJ}/complex.o\
	${OBJ}/main.o


# rule for libed
${OBJ}/%.o: ${SRC}/%.c  
	@ ${CC} -c $< -I ${INCLUDE} -o $@
	@ echo " \033[0;35m  Generating compilation object \033[45;1;37m$@\033[0m\033[0;35m  \033[0m "
	@ echo ''


# rule for create
${BIN}/%: 
	@ ${CC} $< ${OBJ}/*.o -I ${INCLUDE} -o $@ ${FLAGS}
	@ echo " \033[0;33m  Building binary \033[43;1;37m$@\033[0m\033[0;33m  \033[0m "
	@ echo ''


clean:
	@ echo " \033[1;31m  Removing binary \033[41;1;37m${BIN}/${NAME_PROGRAM}\033[0m\033[1;31m and compilation objects \033[41;1;37m$(wildcard ${OBJ}/*.o)\033[0m\033[1;31m and backup files.  \033[0m "
	@ echo ''
	@ rm -rf ${OBJ}/*.o ${BIN}/${NAME_PROGRAM} *~
	@ rmdir ${OBJ} ${BIN}
	@ rm *.csv
