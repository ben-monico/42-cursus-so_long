NAME = so_long

SRCS =	main.c\
		parse_map.c\
		error_check.c\
		libft_utils.c\
		controls.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

MLX_FLAGS = -L mlx -L gnl -lgnl -lmlx -framework OpenGL -framework AppKit 

INCLUDES = -I mlx -I gnl -I .

MLX = mlx/libmlx.a

GNL = gnl/libgnl.a

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(GNL)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(MLX):
	make -C mlx

$(GNL):
	make -C gnl

clean:
	@rm -f $(OBJS)

fclean:	clean 
	@rm -f $(NAME) $(MLX) $(GNL)

re:	fclean all

.PHONY: all clean fclean re