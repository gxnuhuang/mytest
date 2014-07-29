###########################################  
#Makefile for simple programs  
###########################################  
INC=
LIB=

CC=gcc  
CC_FLAG= -g -Wall

PRG=hello
OBJ=main.o
$(PRG):$(OBJ)
	$(CC) $(CC_FLAG) $(INC) $(LIB) -o $@ $(OBJ)
.PRONY:clean  
clean:
	@echo "Removing linked and compiled files......"
	rm -f $(OBJ) $(PRG) *~ 
