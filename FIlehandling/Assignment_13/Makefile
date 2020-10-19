PROJECT_NAME = ALLFUN
BUILD = build

SRC = src/factorial.c \
src/flip.c \
src/isPalindrome.c \
src/isPrime.c \
src/mystrcat.c \
src/mystrcmp.c \
src/mystrcpy.c \
src/query.c \
src/reset.c \
src/set.c \
src/vsum.c \
src/mystrlen.c \
src/unity.c \
src/test.c 

INC = -Iinclude


PROJECT_OUT = $(BUILD)/$(PROJECT_NAME).out

$(PROJECT_NAME):all

.PHONY: run clean all

all: $(SRC) $(BUILD)
		gcc $(SRC) $(INC) -o $(PROJECT_OUT)


object:$(SRC) $(BUILD)
		
run:$(PROJECT_NAME)
		./$(PROJECT_OUT)

clean:$(PROJECT_NAME)
		rm -rf $(BUILD)

$(BUILD):
		mkdir build


