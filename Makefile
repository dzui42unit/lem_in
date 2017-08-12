
NAME = lem_in

SRC = main.c \
	draw_circle.c \
	ft_adjecency_matrix.c \
	ft_check_data.c \
	ft_move_lems.c \
	ft_other.c \
	ft_path_search.c \
	ft_print.c \
	ft_rooms.c \
	ft_set_data.c \
	ft_error.c \
	ft_free.c \
	ft_process_path.c \
	ft_process_queue.c \
	ft_process_rooms.c \
	ft_pixel.c \
	ft_draw_graph.c \
	ft_optimize_path.c

OBJ        = $(SRC:.c=.o)

CFLAGS    = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@make -C libft/
	@make -C minilibx_macos/
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)


clean:
	@make clean -C libft/
	@make clean -C minilibx_macos/
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make fclean -C libft/

re:	fclean $(NAME)