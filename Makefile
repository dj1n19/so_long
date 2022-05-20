# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgenie <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 16:23:01 by bgenie            #+#    #+#              #
#    Updated: 2022/05/20 17:03:12 by bgenie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework Appkit

SRCS_DIR = srcs/

SRCS = srcs/so_long.c \
	   srcs/error.c \
	   srcs/load_map.c \
	   srcs/load_textures.c \
	   srcs/map_check.c \
	   srcs/render.c \
	   srcs/move.c \
	   srcs/free.c \
	   srcs/render_map_objects.c \
	   srcs/hook.c

ARCHIVE_PATH = libft/

LIBS = -lmlx -L$(SRCS_DIR)$(ARCHIVE_PATH) -lft  

INCLUDES = -I$(HEADERS_DIR) -I$(SRCS_DIR)$(ARCHIVE_PATH)

ARCHIVE = libft.a

HEADERS_DIR = includes/

OBJS = $(SRCS:.c=.o)

NAME = so_long

.c.o:
				$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $(<:.c=.o)

all:		$(NAME)

$(ARCHIVE):
				make -C $(SRCS_DIR)$(ARCHIVE_PATH)
			
$(NAME):	$(ARCHIVE) $(OBJS)
				$(CC) $(CFLAGS) $(FRAMEWORK) $(LIBS) $(INCLUDES) $(OBJS) -o $(NAME)

clean:
				make fclean -C $(SRCS_DIR)$(ARCHIVE_PATH)
				rm -f $(OBJS)

fclean:		clean
				rm -f $(SRCS_DIR)$(ARCHIVE_PATH)$(ARCHIVE)
				rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
