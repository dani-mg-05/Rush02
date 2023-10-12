NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c errors.c rush.c write_numbers.c write_numbers2.c ft_atoi.c ft_split.c
OBJS = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				rm -f *.o

fclean:		clean
				rm -f $(NAME)

re:			fclean all
