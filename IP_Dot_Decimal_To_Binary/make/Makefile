## This make file is used to compile the C program which converts the
## given ip address in dotted decimal format into binary format.

CC = gcc
COMPILE = -c -g -Wall
OBJ = ../obj/
BIN = ../bin/
SRC = ../src/
INCLUDE = ../inc/
INC = -I ../inc/
RENAME = -o
VALGRIND = valgrind --tool=memcheck --leak-check=yes



$(BIN)ip_addr_to_bin:$(OBJ)ip_dot_dec_to_binary.o $(INCLUDE)ip_addr_to_bin.h
        $(CC) $(RENAME) $(BIN)ip_addr_to_bin $(OBJ)ip_dot_dec_to_binary.o

$(OBJ)ip_dot_dec_to_binary.o:$(SRC)ip_dot_dec_to_binary.c
        $(CC) $(COMPILE) $(RENAME) $(OBJ)ip_dot_dec_to_binary.o $(SRC)ip_dot_dec_to_binary.c $(INC)



clean:
        rm -rf $(OBJ)ip_dot_dec_to_binary.o
        rm -rf $(BIN)ip_addr_to_bin


valgrind:
        $(VALGRIND) $(BIN)ip_addr_to_bin


