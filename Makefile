NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = ./srcs/backtracking.c \
	   ./srcs/buff_check.c \
	   ./srcs/fillit.c \
	   ./srcs/ft_strlen.c \
	   ./srcs/solver.c \
	   ./srcs/square_free.c \
	   ./srcs/add_size_n_coords.c

OBJS = $(SRCS:%.c=%.o)

$(NAME): $(OBJS) 
	@gcc $(FLAGS) -o $(NAME) $(OBJS)

%.o:%.c 
	@gcc $(FLAGS) -c $< -o $@

all: $(NAME)
	@echo "Fillit created!"

clean:
	@rm -f $(OBJS)
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Fillit removed"

re: fclean all
