CFLAGS = -Wall -g -O0

INC = -Iinclude
SRC = src
TEST = test
BIN = bin


%:
	gcc -o $(BIN)/$@ $(SRC)/*.c $(TEST)/$@_test.c  $(INC) $(CFLAGS) -Wformat=0
	./$(BIN)/$@
