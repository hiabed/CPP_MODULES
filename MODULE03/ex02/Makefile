NAME = FragTrap

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXXFILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp \

OBJ = ${CXXFILES:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all