CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_nbrsize.c ft_utoa.c get_next_line.c get_next_line_utils.c ft_parse_format.c ft_printchar.c ft_printdec.c ft_printf.c ft_printhex.c ft_printptr.c ft_printstr.c ft_printudec.c ft_utohex.c ft_realloc.c

HEADERS_DIR = ./

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

NAME = libft.a

.c.o:
			@ $(CC) $(CFLAGS) -c -I$(HEADERS_DIR) $< -o $(<:.c=.o)
			@ printf "\e[33mcompiling %-30s \e[32m[OK]\e[0m\n" $<

all:		$(OBJS)
				@ printf "\e[34mmaking all %-30s\e[32m[OK]\n\e[0m" $(NAME)
				@ ar -rc $(NAME) $(OBJS)
				@ ranlib $(NAME)

$(NAME):	$(OBJS)
				@ printf "\e[35mmaking %-30s\e[32m[OK]\n\e[0m" $(NAME)
				@ ar -rc $(NAME) $(OBJS)
				@ ranlib $(NAME)

clean:
			@ printf "\e[35m%-41s\e[32m[OK]\e[0m\n" "removing object files"
			@ rm -f $(OBJS)

fclean:		clean
			@ printf "\e[36m%-41s\e[32m[OK]\e[0m\n" "removing binary files"
			@ rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
