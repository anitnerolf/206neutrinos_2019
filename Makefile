##
## EPITECH PROJECT, 2020
## 206neutrinos
## File description:
## makefile
##

SRC	=	src/Main.cpp	\
		src/Neutrinos.cpp

OBJ	=	$(SRC:.cpp=.o)

NAME	=	206neutrinos

CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME) message

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CFLAGS) -lm -I ./include

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f *~ $(NAME)

re:		fclean all

message:
		@echo "Successfully compiled!"
