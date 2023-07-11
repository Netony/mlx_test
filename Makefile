# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:00:32 by dajeon            #+#    #+#              #
#    Updated: 2023/07/11 17:39:25 by dajeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCES = dot/dot.c \
		  dot/dot_operation.c \
		  dot/dot_rotate.c \
		  dot/map_get_data.c \
		  dot/map_operation.c \
		  dot/map_parse.c \
		  dot/ft_mapdup.c \
		  dot/dot_color.c \
		  fdf_error.c \
		  fdf_parse.c \
		  fdf_image.c \
		  fdf_image_set_map.c \
		  fdf_hook.c \
		  fdf_hook_key.c \
		  fdf_putmap.c \
		  fdf_action.c \
		  fdf_action2.c \
		  fdf_utils.c \
		  fdf_utils2.c \
		  fdf_utils3.c \
		  fdf_utils_math.c \
		  fdf_utils_math2.c \
		  fdf_utils_matrix.c \
		  ft_toklen.c \
		  ft_atoi_base.c 

SOURCES_MANDA = main.c 
SOURCES_BONUS = main_bonus.c
			   
INCLUDES = fdf.h fdf_utils.h dot.h

LIBFT = libft.a
LIB = ft 

# **************************************************************************** #

LIB_DIR = libft
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = incs

SRCS := $(addprefix $(SRC_DIR)/, $(SOURCES))
SRCS_MANDA := $(addprefix $(SRC_DIR)/, $(SOURCES_MANDA))
SRCS_BONUS := $(addprefix $(SRC_DIR)/, $(SOURCES_BONUS))

OBJS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
OBJS_MANDA = $(addprefix $(OBJ_DIR)/, $(SOURCES_MANDA:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(SOURCES_BONUS:.c=.o))

INCS := $(addprefix $(INC_DIR)/, $(INCLUDES))
LIBFT := $(addprefix $(LIB_DIR)/, $(LIBFT))

ifdef WITH_BONUS
	OBJS_NEW = $(OBJS_BONUS) $(OBJS) 
else
	OBJS_NEW = $(OBJS_MANDA) $(OBJS) 
endif

# **************************************************************************** #

MAKE = make
CC = gcc
AR = ar
RM = rm

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
LIBFLAGS = -lm -lmlx -framework OpenGl -framework AppKit -l$(LIB) -L$(LIB_DIR)

ARFLAGS = crus
RMFLAGS = -rf

# Commands ******************************************************************* #

all : 
	$(RM) $(RMFLAGS) $(OBJS_BONUS)
	$(MAKE) $(NAME) 

bonus : 
	$(RM) $(RMFLAGS) $(OBJS_MANDA)
	$(MAKE) $(NAME) WITH_BONUS=1

clean :
	$(RM) $(RMFLAGS) objs
	$(MAKE) -C libft clean

fclean : 
	$(RM) $(RMFLAGS) objs
	$(RM) $(RMFLAGS) $(NAME)
	$(MAKE) -C libft fclean

re : 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re

# Dependency ***************************************************************** #

$(NAME) : $(OBJS_NEW) $(LIBFT) $(LIBFTPRINTF) $(LIBGNL)
	$(CC) $(CFLAGS) $(OBJS_NEW) -o $(NAME) $(LIBFLAGS)

$(LIBFT): 
	$(MAKE) -j3 -C $(LIB_DIR) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) | $(OBJ_DIR) $(OBJ_DIR)/dot
	$(CC) $(CFLAGS) $< -c -I $(INC_DIR) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/dot:
	mkdir $(OBJ_DIR)/dot

