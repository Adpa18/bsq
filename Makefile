##
## Makefile for Makefile in /home/wery_a/rendu/BSQ/Test
## 
## Made by adrien wery
## Login   <wery_a@epitech.net>
## 
## Started on  Mon Jan 12 15:48:24 2015 adrien wery
## Last update Thu Jan 15 20:12:13 2015 adrien wery
##

SRC	= main.c \
	  get_file.c \
	  str.c

CC	= gcc

CFLAGS	= -W -Wall -Wextra

RM	= rm -f

NAME	= bsq

OBJ	= $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
