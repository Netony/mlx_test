# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 09:00:32 by dajeon            #+#    #+#              #
#    Updated: 2023/07/11 12:27:47 by dajeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SOURCES = dot/dot.c \
		  dot/dot_operation.c \
		  dot/dot_rotate.c \
		  dot/map_get_data.c \
		  dot/map_operation.c
		  dot/map_parse.c
SOURCES_MANDA = main.c \
				fdf_image.c fdf_image_set_dot.c \
				fdf_hook.c \
				fdf_parse.c \
				fdf_put.c \
				fdf_size.c fdf_delete.c \
				ft_toklen.c ft_atoi_base.c ft_atoi_new.c \
				fdf_math.c \
				dup_oper.c dup_center.c \
				fdf_dot_rotate.c \
				fdf_matrix.c \

SOURCES_BONUS =
			   
INCLUDES = fdf.h

LIBFT = libft.a
LIB = ft 

# **************************************************************************** #

LIB_DIR = libft
SRC_DIR = srcs
OBJ_DIR = objs
INC_DIR = srcs

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

CFLAGS = -Wall -Wextra -Werror
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
	$(CC) $(CFLAGS) $(OBJS_NEW) -I $(INC_DIR) -o $(NAME) $(LIBFLAGS)

$(LIBFT): 
	$(MAKE) -j3 -C $(LIB_DIR) all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -c -I $(SRC_DIR) -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

