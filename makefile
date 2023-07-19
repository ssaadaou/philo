NAME = philo
HEADER = philo.h

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = utils.c input.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all