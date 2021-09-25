NAME = pipex.a
CC = gcc #-fsanitize=address -g3 # C compiler
CFLAGS = -Wall -Werror -Wextra -I.   # C flags
RM = rm -f   # rm command


SRCS = pipex.c\
	utils.c \
	utils_pipex.c \
	start_pipex.c \

OBJS = $(SRCS:.c=.o)

all: ${NAME}
	@printf "Makefile for Pipex starts\n"

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)
	$(CC) $(NAME) -o pipex

clean:
	$(RM) $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm pipex

re: fclean all

.PHONY: all clean fclean re