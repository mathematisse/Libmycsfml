##
## PERSONNAL PROJECT, 2023
## Libmycsfml
## File description:
## Makefile for the compilation of the lib
##

NAME		=	libmycsfml.a

SRC			=	canvas_factory.c		\
				canvas_event.c			\
				canvas_update.c			\
				cursor.c				\
				scene_event.c			\
				scene_update.c			\
				scene_factory.c			\
				tools.c					\
				panel/panel_factory.c	\
				panel/panel_hover.c		\
				panel/panel_resize.c	\
				panel/panel_select.c	\
				panel/panel_tests.c		\
				panel/panel.c			\
				panel/rectransform.c	\
				program/program_start.c	\
				program/program_event.c	\
				program/program.c		\
				ui_panels/button.c		\
				ui_panels/dropdown.c	\
				ui_panels/input.c		\
				ui_panels/panel_empty.c	\
				ui_panels/text.c		\

CFLAGS		=	-g -W -Wall -Wextra -Wpedantic -Werror -I./include

CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-system

SRC			:=	$(addprefix src/, $(SRC))

OBJ			=	$(SRC:.c=.o)

DEMOBJ		=	tests/demo.o tests/demo_panels.o

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

demo		: 	$(NAME) $(DEMOBJ)
	gcc -o demo $(DEMOBJ) $(CFLAGS) $(CSFML) -L. -lmycsfml

run			: 	demo
	./demo

.PHONY 		: 	all clean fclean re run
