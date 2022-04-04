NAME = so_long

# MLX #
MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a

# LIBFT #
LIBFT_PATH = libft/
LIBFT_LIB = $(LIBFT_PATH)libft.a

# FILES #
CFILES = main.c \


# COMPILATION #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

OBJECTS = $(CFILES:.c=.o)

all:

${LIBFT_LIB}:
	@make -s all -C ${LIBFT_PATH}

norm: all
		norminette server.c client.c

.PHONY: all clean fclean re norm