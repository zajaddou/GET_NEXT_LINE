NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME) clean 

$(NAME): $(OBJ) 
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

paco:
	clear && paco -in -t 2

run:
	${CC} main.c get_next_line.a && clear && ./a.out && rm a.out get_next_line.a

re: run fclean all
