##
## PERSONAL PROJECT, 2023
## Libmycsfml
## File description:
## Makefile for the compilation of the lib
##

NAME		=	libmycsfml.a

SRC			=	mouse_evt.c				\
				tools.c					\
				panel/panel_hover.c		\
				panel/panel_resize.c	\
				panel/panel_select.c	\
				panel/panel.c			\
				panel/rectransform.c	\
				program/program_start.c	\
				program/program_tools.c	\
				program/program.c		\
				ui_panels/button.c		\
				ui_panels/dropdown.c	\
				ui_panels/input.c		\
				ui_panels/panel_empty.c	\
				ui_panels/text.c		\

CFLAGS		=	-W -Wall -Wextra -I./include

CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-system

SRC			:=	$(addprefix src/, $(SRC))

OBJ			=	$(SRC:.c=.o)

$(NAME)		:	$(OBJ)
	ar rc $@ $^

all			:	$(NAME)

%.o			:	%.c
	gcc -c -o $@ $< $(CFLAGS)

clean		:
	rm -f $(OBJ)
	rm -f *~
	rm -f #*#
	rm -f tests/*.o
	rm -f demo

fclean		: 	clean
	rm -f $(NAME)

re			: 	fclean all

demo		: 	$(NAME) tests/demo.o tests/demo_panels.o
	gcc -o demo tests/demo.o tests/demo_panels.o $(CFLAGS) $(CSFML) -L. -lmycsfml

.PHONY 		: 	all clean fclean re
