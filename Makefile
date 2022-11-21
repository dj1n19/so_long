# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 16:23:01 by bgenie            #+#    #+#              #
#    Updated: 2022/11/21 14:15:05 by bgenie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FRAMEWORK = -framework OpenGL -framework Appkit

MANDATORY_SRCS_DIR = srcs/mandatory

BONUS_SRCS_DIR = srcs/bonus

SRCS =		 	${MANDATORY_SRCS_DIR}/error.c \
				${MANDATORY_SRCS_DIR}/free.c \
				${MANDATORY_SRCS_DIR}/hook.c \
				${MANDATORY_SRCS_DIR}/list.c \
				${MANDATORY_SRCS_DIR}/load_map.c \
				${MANDATORY_SRCS_DIR}/load_textures.c \
				${MANDATORY_SRCS_DIR}/map_check.c \
				${MANDATORY_SRCS_DIR}/move.c \
				${MANDATORY_SRCS_DIR}/pathfinding.c \
				${MANDATORY_SRCS_DIR}/pathfinding2.c \
				${MANDATORY_SRCS_DIR}/pathfinding3.c \
				${MANDATORY_SRCS_DIR}/render_map_objects.c \
				${MANDATORY_SRCS_DIR}/render.c \
				${MANDATORY_SRCS_DIR}/so_long.c

SRCS_BONUS =	${BONUS_SRCS_DIR}/attack_bonus.c \
				${BONUS_SRCS_DIR}/attack_utils_bonus.c \
				${BONUS_SRCS_DIR}/character_check_bonus.c \
				${BONUS_SRCS_DIR}/death_foes_bonus.c \
				${BONUS_SRCS_DIR}/error_bonus.c \
				${BONUS_SRCS_DIR}/free_bonus.c \
				${BONUS_SRCS_DIR}/hook_bonus.c \
				${BONUS_SRCS_DIR}/init_bonus.c \
				${BONUS_SRCS_DIR}/init_characters_bonus.c \
				${BONUS_SRCS_DIR}/list_bonus.c \
				${BONUS_SRCS_DIR}/load_foes_attack_bonus.c \
				${BONUS_SRCS_DIR}/load_foes_bonus.c \
				${BONUS_SRCS_DIR}/load_foes_death.c \
				${BONUS_SRCS_DIR}/load_items_bonus.c \
				${BONUS_SRCS_DIR}/load_map_bonus.c \
				${BONUS_SRCS_DIR}/load_player_attack_bonus.c \
				${BONUS_SRCS_DIR}/load_player_bonus.c \
				${BONUS_SRCS_DIR}/load_textures_bonus.c \
				${BONUS_SRCS_DIR}/map_check_bonus.c \
				${BONUS_SRCS_DIR}/move_foes_bonus.c \
				${BONUS_SRCS_DIR}/move_player_bonus.c \
				${BONUS_SRCS_DIR}/pathfinding_bonus.c \
				${BONUS_SRCS_DIR}/pathfinding2_bonus.c \
				${BONUS_SRCS_DIR}/pathfinding3_bonus.c \
				${BONUS_SRCS_DIR}/place_foes_bonus.c \
				${BONUS_SRCS_DIR}/player_animation_bonus.c \
				${BONUS_SRCS_DIR}/render_bonus.c \
				${BONUS_SRCS_DIR}/render_characters_bonus.c \
				${BONUS_SRCS_DIR}/render_items_bonus.c \
				${BONUS_SRCS_DIR}/render_map_bonus.c \
				${BONUS_SRCS_DIR}/render_map_objects_bonus.c \
				${BONUS_SRCS_DIR}/so_long_bonus.c \
				${BONUS_SRCS_DIR}/spell_cast_bonus.c \
				${BONUS_SRCS_DIR}/utils_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

LIB_DIR = lib

LIB_NAME =	libmlx.a \
			libft.a

LIB = -lmlx -lft

MANDATORY_INCLUDES_DIR = includes/mandatory

BONUS_INCLUDES_DIR = includes/bonus

NAME = so_long

NAME_BONUS = so_long_bonus

all:			${NAME}

libft:
				make -C ${MANDATORY_SRCS_DIR}/libft
				mv ${MANDATORY_SRCS_DIR}/libft/libft.a ${LIB_DIR}
				cp ${MANDATORY_SRCS_DIR}/libft/libft.h ${MANDATORY_INCLUDES_DIR}
				cp ${MANDATORY_SRCS_DIR}/libft/get_next_line.h ${MANDATORY_INCLUDES_DIR}
				cp ${MANDATORY_SRCS_DIR}/libft/ft_printf.h ${MANDATORY_INCLUDES_DIR}

libft_bonus:
				make -C ${BONUS_SRCS_DIR}/libft
				mv ${BONUS_SRCS_DIR}/libft/libft.a ${LIB_DIR}
				cp ${BONUS_SRCS_DIR}/libft/libft.h ${BONUS_INCLUDES_DIR}
				cp ${BONUS_SRCS_DIR}/libft/get_next_line.h ${BONUS_INCLUDES_DIR}
				cp ${BONUS_SRCS_DIR}/libft/ft_printf.h ${BONUS_INCLUDES_DIR}

${NAME}:		libft ${OBJS}
				${CC} ${CFLAGS} ${FRAMEWORK} -o ${NAME} -L${LIB_DIR} ${LIB} -I${MANDATORY_INCLUDES_DIR} ${OBJS}

bonus:			libft_bonus ${OBJS_BONUS}
				${CC} ${CFLAGS} ${FRAMEWORK} -o ${NAME_BONUS} -L${LIB_DIR} ${LIB} -I${BONUS_INCLUDES_DIR} ${OBJS_BONUS}

clean:
				make -C ${MANDATORY_SRCS_DIR}/libft clean
				make -C ${BONUS_SRCS_DIR}/libft clean
				rm -f ${OBJS} ${OBJS_BONUS}

fclean:			clean
				rm -f ${NAME} ${NAME_BONUS} ${LIB_DIR}/libft.a

re:				fclean all
