NAME = philo
HEADER = philo.h

CC = cc

# CFLAGS = -fsanitize=thread

RM = rm -rf

SRC = utils.c input.c routine.c death_note.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS)  $(OBJ) -o $(NAME) 

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all