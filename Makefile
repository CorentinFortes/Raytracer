##
## EPITECH PROJECT, 2022
## B-OOP-400-MAR-4-1-raytracer-corentin.fortes
## File description:
## Makefile
##

NAME = raytracer
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    MAC_FLAGS = -I /opt/homebrew/Cellar/libconfig/1.7.3/include -L /opt/homebrew/Cellar/libconfig/1.7.3/lib
else
    MAC_FLAGS = -I /usr/include/libconfig -L /usr/lib/x86_64-linux-gnu
endif

$(NAME):
	g++ -o $(NAME) $(SRC) -g -std=c++20 -lconfig++ $(MAC_FLAGS)
	rm -fr *.dSYM

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
