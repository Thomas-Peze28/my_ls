##
## EPITECH PROJECT, 2024
## makefile pong seb
## File description:
## makfile
##

SRC	=	src/main.c	\
		src/ls.c	\
		src/my_print_type.c	\
		src/my_print_permissions.c	\
		src/my_readdir.c	\
		src/my_readdir_hid.c	\
		src/my_readfiles.c	\
		src/my_blocksize.c	\
		src/is_file.c	\
		src/flags.c	\

NAME	=	my_ls

OBJ	=	$(SRC:.c=.o)

INC	= 	-I./include/

LDFLAGS =	-L./lib -lmy

CFLAGS = -Wall -Wextra -Werror $(INC) $(LDFLAGS)

all: build_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

build_lib:
		make -C ./lib/my/

clean_lib:
		make clean -C ./lib/my/

clean: clean_lib
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all fclean clean re
