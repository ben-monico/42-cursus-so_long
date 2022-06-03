NAME = so_long

SRCS =	main.c\
		bonus.c\
		controls.c\
		error_check.c\
		libft_utils.c\
		libft_utils2.c\
		parse_map.c\
		screen.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

LINKERS = -L mlx -lmlx -L gnl -lgnl -L ft_printf -lftprintf

MLX_FLAGS = -framework OpenGL -framework AppKit 

INCLUDES = -I mlx -I gnl -I ft_printf -I . 

MLX = mlx/libmlx.a

GNL = gnl/libgnl.a

PRINTF = ft_printf/libftprintf.a

.c.o:
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(GNL) $(PRINTF)
	$(CC) $(FLAGS) $(LINKERS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(MLX):
	make -C mlx

$(GNL):
	make -C gnl

$(PRINTF):
	make -C ft_printf

clean:
	@rm -f $(OBJS)

fclean:	clean 
	@rm -f $(NAME) $(MLX) $(GNL) $(PRINTF)

re:	fclean all

.PHONY: all clean fclean re