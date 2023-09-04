NAME = minishell
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline


SRCS = ./main.c \
		./parsing.c \
		./cmdsplit.c \
		./error.c \
		./expand.c \
		./utils.c \
		./tilde.c \
		./cmdsub.c \
		./echo.c \

LIBFT = libft.a
LIBFT_DIR = ./libft
OBJS_DIR = ./objs
INC_DIR = ./headers
SRCS_DIR = srcs/Main \
		   srcs/Parsing \
		   srcs/Error \
		   srcs/Builtins \

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -o $@ -I$(INC_DIR) -I$(LIBFT_DIR) -c $^

debug:
	@$(MAKE) -n $(NAME)

clean :
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean : clean
	@$(RM) $(NAME)
	@make -C libft fclean

echo:
	$(CC) echo.c

re : fclean all