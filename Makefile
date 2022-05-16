NAME = so_long

SRCS = main.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

INCLUDES = -I minilibx -I .

MLX = mlx/libmlx.a

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(FLAGS) -L mlx -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

$(MLX):
	make -C mlx

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re