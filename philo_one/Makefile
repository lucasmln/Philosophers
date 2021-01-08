NAME			= philo_one

CFLAGS			= -Wall -Wextra -Werror -g3 #-fsanitize=address

SRC				=	\
					./action.c \
					./ft_atoi.c \
					./ft_isdigit.c \
					./ft_strdel.c \
					./ft_strlen.c \
					./ft_uitoa.c \
					./init.c \
					./main.c \
					./parse.c \
					./time.c \
					./writer.c \

ROAD_S			= $(SRC)

ROAD_O			= $(OBJ)

ROAD_B			= $(SRCB)


OBJ				= $(SRC:.c=.o)

CC				= clang

HEADER_DIR		=  -I ./philosophers.h 

$(NAME) :		$(OBJ)
				$(CC) $(OBJ) -ltermcap -o $(NAME)

LIBFT			= libft

all :			$(NAME)

clean :
				@rm -f $(ROAD_O)

fclean :
				@rm -f $(ROAD_O)
				@rm -f $(NAME)

re : 			fclean all

.PHONY: 		all clean fclean re
