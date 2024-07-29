.PHONY = all clean fclean

NAME = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRCS =	ft_memset.c				\
		ft_bzero.c 				\
		ft_memcpy.c 			\
		ft_memccpy.c 			\
		ft_memmove.c 			\
		ft_memchr.c 			\
		ft_memcmp.c 			\
		ft_strlen.c 			\
		ft_isalpha.c 			\
		ft_isdigit.c 			\
		ft_isalnum.c 			\
		ft_isascii.c 			\
		ft_isprint.c 			\
		ft_toupper.c 			\
		ft_tolower.c 			\
		ft_strchr.c  			\
		ft_strncmp.c 			\
		ft_strlcpy.c 			\
		ft_strlcat.c 			\
		ft_strnstr.c 			\
		ft_atoi.c 				\
		ft_calloc.c 			\
		ft_substr.c 			\
		ft_strtrim.c 			\
		ft_split.c 				\
		ft_itoa.c 				\
		ft_strmapi.c 			\
		ft_putchar_fd.c 		\
		ft_putstr_fd.c 			\
		ft_putendl_fd.c 		\
		ft_putnbr_fd.c 			\
		ft_strrchr.c 			\
		ft_caracter.c 			\
		ft_digit.c 				\
		ft_fill_struct.c 		\
		ft_functons.c 			\
		ft_hexa.c 				\
		ft_hexadecimal.c 		\
		ft_percent.c 			\
		ft_pointeur.c 			\
		ft_printf.c 			\
		ft_printf_utils.c 		\
		ft_string.c 			\
		ft_unsigned.c 			\
		ft_strjoin.c			\
		get_next_line.c 		\
#		get_next_line_utils.c	\

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(TEXT) $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS) $(NAME)
	make clean

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all
