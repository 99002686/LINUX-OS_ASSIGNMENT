PROJECT_NAME = ALLFUN

SRC = factorial.c \
flip.c \
isPalindrome.c \
isPrime.c \
mystrcat.c \
mystrcmp.c \
mystrcpy.c \
query.c \
reset.c \
set.c \
vsum.c \
mystrlen.c \
unity.c \
test.c 

INC = mystring.h \
myutils.h \
bitmask.h \
test.h \
unity.h \
unity_internals.h


PROJECT_OUT = $(PROJECT_NAME).out

$(PROJECT_NAME): $(SRC)
		gcc $(SRC) $(INC) -o $(PROJECT_OUT)

run:$(PROJECT_NAME)
		./$(PROJECT_OUT)

clean:$(PROJECT_NAME)
		rm -f *.out


