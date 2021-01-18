
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
