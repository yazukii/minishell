NAME = minishell

FILES = srcs/main.c \
		srcs/parsing.c \
		srcs/cmdsplit.c \
		srcs/error.c \
		srcs/expand.c \
		srcs/utils.c \
		srcs/tilde.c \
		srcs/cmdsub.c

LIBFT = libft/libft.

OBJS = $(FILES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c 
	@$(CC) -c -g $< -o $@

all : $(NAME)

libf :
	@make -C ./libft

$(NAME) : $(OBJS) libf
	@$(CC) $(OBJS) libft/libft.a $(CFLAGS) -lreadline -o $(NAME)

clean :
	@rm -f $(SRCS)/$(OBJS)
	@make -C libft clean

fclean : clean
	@rm -f $(NAME)
	@make -C libft fclean

re : fclean all