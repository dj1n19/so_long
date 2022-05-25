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

SRCS_DIR_BONUS = bonus/srcs/

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

SRC_BONUS = bonus/srcs/attack_bonus.c \
			bonus/srcs/character_check_bonus.c \
			bonus/srcs/draw_item_bonus.c \
			bonus/srcs/error_bonus \
			bonus/srcs/free_bonus.c \
			bonus/srcs/hook_bonus.c \
			bonus/srcs/init_bonus.c \
			bonus/srcs/init_characters_bonus.c \
			bonus/srcs/load_foes_bonus.c \
			bonus/srcs/load_items_bonus.c \
			bonus/srcs/load_map_bonus.c \
			bonus/srcs/load_player_bonus.c \
			bonus/srcs/load_textures_bonus.c \
			bonus/srcs/map_check_bonus.c \
			bonus/srcs/move_bonus.c \
			bonus/srcs/move_foes_bonus.c \
			bonus/srcs/move_player_bonus.c \
			bonus/srcs/place_foes_bonus.c \
			bonus/srcs/player_animation.c \
			bonus/srcs/render_bonus_.c \
			bonus/srcs/render_characters_bonus.c \
			bonus/srcs/render_map_objects_bonus.c \
			bonus/srcs/so_long_bonus.c

ARCHIVE_PATH = libft/

LIBS = -lmlx -L$(SRCS_DIR)$(ARCHIVE_PATH) -lft  

LIBS_BONUS = -lmlx -L$(SRCS_DIR_BONUS)$(ARCHIVE_PATH) -lft

INCLUDES = -I$(HEADERS_DIR) -I$(SRCS_DIR)$(ARCHIVE_PATH)

INCLUDES_BONUS = -I$(HEADERS_DIR_BONUS) -I$(SRCS_DIR_BONUS)$(ARCHIVE_PATH)

ARCHIVE = libft.a

HEADERS_DIR = includes/

HEADERS_DIR_BONUS = bonus/includes/

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = so_long

NAME_BONUS = so_long_bonus

.c.o:
				$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $(<:.c=.o)

all:		$(NAME) bonus

$(ARCHIVE):
				make -C $(SRCS_DIR)$(ARCHIVE_PATH)
			
$(NAME):	$(ARCHIVE) $(OBJS)
				$(CC) $(CFLAGS) $(FRAMEWORK) $(LIBS) $(INCLUDES) $(OBJS) -o $(NAME)

bonus:
				make -C $(SRCS_DIR_BONUS)$(ARCHIVE_PATH)
				$(CC) $(CFLAGS) -c $(INCLUDES_BONUS) $< -o $(<:.c=.o)
				$(CC) $(CFLAGS) $(FRAMEWORK) $(LIBS_BONUS) $(INCLUDES_BONUS) $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
				make fclean -C $(SRCS_DIR)$(ARCHIVE_PATH)
				rm -f $(OBJS)
				make fclean -C $(SRCS_DIR_BONUS)$(ARCHIVE_PATH)
				rm -f $(OBJS_BONUS)

fclean:		clean
				rm -f $(SRCS_DIR)$(ARCHIVE_PATH)$(ARCHIVE)
				rm -f $(NAME)
				rm -f $(SRCS_DIR_BONUS)$(ARCHIVE_PATH)$(ARCHIVE)
				rm -f $(NAME_BONUS)

re:			fclean all

.PHONY:		all clean fclean re
