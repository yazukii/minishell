FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
		ft_calloc.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_itoa.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_striteri.c \
		ft_strcmp.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_split.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strmapi.c \
		ft_strnstr.c \
		ft_strtrim.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_strrev.c \
		ft_intlen.c \
		ft_stod.c

SRC_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	echo "$(NAME) created"
	ranlib $(NAME)
	echo "$(NAME) indexed"

bonus: $(OBJ_B)
	ar rc $(NAME) $(OBJ_B)
	echo "$(NAME) created"
	ranlib $(NAME)
	echo "$(NAME) indexed"

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
	echo "OBJ deleted"

fclean: clean
	rm -f $(NAME)
	echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re


#$(NAME): isalpha.o
#	ar rcs $(NAME) *.o

#isalpha.o: isalpha.c
#	gcc -Wall -Werror -Wextra -c isalpha.c -o isalpha.o
