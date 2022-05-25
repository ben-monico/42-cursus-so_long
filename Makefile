NAME = so_long

SRCS =	main.c\
		parse_map.c\
		error_check.c\
		libft_utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

INCLUDES = -I mlx -I gnl -I .

MLX = mlx/libmlx.a

GNL = gnl/libgnl.a

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(FLAGS) -L mlx -L gnl -lgnl -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

$(MLX):
	make -C mlx

$(GNL):
	make -C gnl

clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re