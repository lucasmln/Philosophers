# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmoulin <lmoulinn@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 19:33:23 by lmoulin           #+#    #+#              #
#    Updated: 2020/11/25 19:28:14 by lmoulin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -pthread
endif

NAME = philo_two

SRCS = 		action.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_strdel.c \
		ft_strlen.c \
		ft_uitoa.c \
		init.c \
		main.c \
		parse.c \
		time.c \
		writer.c \

OBJ = $(SRCS:.c=.o)


CC = gcc

CFLAGS += -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
clean : 
			rm -rf $(OBJ)

fclean :	clean
			rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean
