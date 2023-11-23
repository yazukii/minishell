NAME = minishell
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -lreadline


SRCS = ./main.c \
		./signal.c \
		./init.c \
		./utils_lst_env.c \
		./parseur.c \
		./expand.c \
		./pre_tokken.c \
		./get_redir.c \
		./get_word.c \
		./tokken.c \
		./utils_parsing.c \
		./utils_lst.c \
		./utils_lst_tokken.c \
		./error.c \
		./expand.c \
		./echo.c \
		./pwd.c \
		./env.c \
		./export.c \
		./cd.c \
		./builtin.c \
		./check_tokken.c \
		./heredoc.c \
		./utils_lst_args.c \
		./free_all.c \
		./env_utils.c \
		./unset.c \
		./execution.c \
		./handle_signal.c \
		./get_quote.c \
		./redir_utils.c \
		./exec_utils.c \
		./one_cmd.c

LIBFT = libft.a
LIBFT_DIR = ./libft
OBJS_DIR = ./objs
INC_DIR1 =	./headers
INC_DIR2 = ./libft/includes

SRCS_DIR = srcs/Main \
		   srcs/Parsing \
		   srcs/Error \
		   srcs/Builtins \
		   srcs/Execution \
		   srcs/Initialisation \
		   srcs/Free \
		   srcs/Signals \
		   srcs/utils \

OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(SRCS_DIR)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -g -o $@ -I$(INC_DIR1) -I$(INC_DIR2) -I$(LIBFT_DIR) -c $^

debug:
	@$(MAKE) -n $(NAME)

clean :
	@$(RM) $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean : clean
	@$(RM) $(NAME)
	@make -C libft fclean

echo:
	$(CC) srcs/Builtins/echo.c

re : fclean all