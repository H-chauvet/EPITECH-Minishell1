##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC				=	src/main.c \
					src/builtins/my_env.c \
					src/builtins/my_setenv.c \
					src/builtins/my_unsetenv.c \
					src/builtins/my_exec.c \
					src/builtins/my_cd.c \
					src/get_path.c \
					src/get_homepath.c \
					src/builtins/exec_init.c \

OBJ				=	$(SRC:.c=.o)

NAME			=	mysh

CFLAGS			=	-Wall -Werror -I include/



all:				$(NAME)

$(NAME):			$(OBJ)
					make re -C lib/my/
					cc $(OBJ) -o $(NAME) -L./lib/ -lmy

tests_run:  unit_tests
			./tests/unit_tests

unit_tests:
			make re -C lib/my
			make re -C tests/

clean:
					rm -f $(OBJ)

fclean:				clean
					rm -f $(NAME)
					rm lib/libmy.a
					make fclean -C lib/my/

re:					fclean all

.PHONY:
					all clean fclean re