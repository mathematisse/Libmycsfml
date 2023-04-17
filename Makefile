##
## EPITECH PROJECT, 2023
## Libmycsfml
## File description:
## Makefile for the compilation of the lib
##

NAME		=	libmycsfml.a

SRC			=	canvas/canvas_event.c		\
				canvas/canvas_factory.c		\
				canvas/canvas_update.c		\
				cursor.c					\
				scene/scene_event.c			\
				scene/scene_factory.c		\
				scene/scene_update.c		\
				gratools.c					\
				tools.c						\
				panel/panel_factory.c		\
				panel/panel_hover.c			\
				panel/panel_resize.c		\
				panel/panel_select.c		\
				panel/panel_tests.c			\
				panel/panel.c				\
				panel/rtrans_bar_factory.c	\
				panel/rtrans_factory.c		\
				panel/rtrans_update.c		\
				program/program_event.c		\
				program/program_execute.c	\
				program/program_factory.c	\
				program/program_start.c		\
				ui_panels/button.c			\
				ui_panels/dropdown.c		\
				ui_panels/input.c			\
				ui_panels/empty.c			\
				ui_panels/text.c

CFLAGS		=	-W -Wall -Wextra -Wpedantic -Werror -I./include

CSFML		=	-lcsfml-graphics -lcsfml-window -lcsfml-system

SRC			:=	$(addprefix src/, $(SRC))

OBJ			=	$(SRC:.c=.o)

DEMOBJ		=	tests/demo_main.o tests/demo_game.o tests/demo_menu.o

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

debug		: 	CFLAGS += -g
debug		: 	re demo

demo		: 	$(NAME) $(DEMOBJ)
	gcc -o demo $(DEMOBJ) $(CFLAGS) $(CSFML) -L. -lmycsfml

run			: 	demo
	./demo

.PHONY 		: 	all clean fclean re run
