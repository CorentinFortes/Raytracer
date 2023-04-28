##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-raytracer-corentin.fortes
## File description:
## Makefile
##

NAME = raytracer
SRC =	*.cpp
OBJ = $(SRC:.cpp=.o)
$(NAME) :
		 g++ -o $(NAME) $(SRC) -L -g -std=c++20 -lconfig++ -I /opt/homebrew/Cellar/libconfig/1.7.3/include -L /opt/homebrew/Cellar/libconfig/1.7.3/lib
		 rm -fr *.dSYM

all : $(NAME)

clean :
		 rm -f $(OBJ)

fclean : clean
		 rm -f $(NAME)

re :	 fclean all