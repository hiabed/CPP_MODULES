NAME = phonebook

CC = c++

CXXFLAGS = -Wall -Wextra -Werror #-std=c++98

CXXFILES = PhoneBook.cpp main.cpp\

OBJ = ${CXXFILES:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all