##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compil
##

SRCS =	bsmyhunter.c \
		display_sprite.c \
		level2.c \
		draw_hit_fall.c \
		draw_hit_fall2.c \
		mydog.c \
		mydog2.c \
		menu.c \
		font.c \
		split_main.c \

OBJS = $(SRCS:.c=.o)

NAME = my_hunter

all : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRCS) -lcsfml-graphics -lcsfml-audio

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
