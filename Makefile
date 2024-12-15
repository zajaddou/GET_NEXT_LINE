
NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

BONUS_SRC = get_next_line_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME) clean 

$(NAME): $(OBJ) 
	ar -rcs $(NAME) $(OBJ)

%.o: %.c get_next_line.h 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUS_SRC) $(BONUS_OBJ)
	ar -rcs $(NAME) $(BONUS_OBJ)
