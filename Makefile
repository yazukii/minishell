NAME = minishell

FILES = srcs/main.c \
		srcs/parsing.c \
		srcs/echo.c

LIBFT = libft/libft.a

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

sip : $(NAME)
	codesign -s - -v -f --entitlements =(echo -n '<?xml version="1.0" encoding="UTF-8"?> \
	<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "https://www.apple.com/DTDs/PropertyList-1.0.dtd"\> \
	<plist version="1.0"> \
		<dict> \
			<key>com.apple.security.get-task-allow</key> \
			<true/> \
		</dict> \
	</plist>') minishell

clean :
	rm -f $(SRCS)/$(OBJS)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all