NAME = megaphone

CC = g++

CFLAGS = -Wall -Wextra -Werror

CFILES = megaphone.cpp \

OBJ = ${CFILES:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

