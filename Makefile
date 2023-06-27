NAME = minishell

FILES = srcs/main.c \
		srcs/parsing.c \
		srcs/echo.c

LIBFT = libft/libft.

OBJS = $(FILES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o : %.c 
	$(CC) -c $< -o $@

all : $(NAME)

libf :
	make -C ./libft

$(NAME) : $(OBJS) libf
	$(CC) $(OBJS) libft/libft.a $(CFLAGS) -lreadline -o $(NAME)

clean :
	rm -f $(SRCS)/$(OBJS)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all