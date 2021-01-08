# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/22 19:33:23 by jvaquer           #+#    #+#              #
#    Updated: 2020/11/25 19:28:14 by jvaquer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	CFLAGS += -pthread
endif

NAME = philo_one

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
