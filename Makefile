CC = cc

CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS =  main.c get_next_line.c get_next_line_utils.c parsing.c \
		ft_trim.c trim_start_end.c ft_split.c exit.c \
		validation.c validation_pt2.c flood_fill.c start_game.c \
		press_key.c itoa.c init_map.c

INCS = so_long.h get_next_line.h

NAME = so_long

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) Makefile so_long.h
		$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean