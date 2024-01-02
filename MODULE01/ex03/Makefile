NAME = Weapon

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXXFILES = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp \

OBJ = ${CXXFILES:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all