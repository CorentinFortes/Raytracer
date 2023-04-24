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
		 g++ -o $(NAME) $(SRC) -g -std=c++20 -Wall -Werror
		 rm -fr *.dSYM

all : $(NAME)

clean :
		 rm -f $(OBJ)

fclean : clean
		 rm -f $(NAME)

re :	 fclean all