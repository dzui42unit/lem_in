/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:34:47 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 21:34:51 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# include "libft/ft_printf.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libmlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# define WIDTH 1024
# define HEIGHT 640

typedef struct		s_room
{
	struct s_room	*next;
	uintmax_t		x;
	uintmax_t		y;
	char			*name;
	int				end;
	int				start;
	int				id;
	uintmax_t		active_lem;
}					t_room;

typedef struct		s_path
{
	struct s_path	*next;
	int				*path;
	int				length;
	int				active;
}					t_path;

typedef struct		s_lem
{
	uintmax_t		ants;
	uintmax_t		init;
	t_room			*head;
	t_path			*path;
	void			*mlx;
	void			*win;
	void			*image;
	char			*input_data;
	int				**adj_matrix;
	int				*visited;
	int				show_path;
	int				counter;
	int				flag;
	int				visual;
	int				radius;
	int				radius_2;
	int				x_1;
	int				x_2;
	int				y_1;
	int				y_2;
	float			error_1;
	float			error_2;
	float			dx;
	float			dy;
	int				sign_x;
	int				sign_y;
	int				start;
	int				index;
	int				size;
	int				end;
	int				start_counter;
	int				end_counter;
	int				*lems;
}					t_lem;

uintmax_t			ft_atoi_unsigned(char *str);
t_room				*ft_where_the_ant_is(t_room *head, uintmax_t active_lem);
t_room				*ft_create_room(t_lem *lem, char *data);
t_room				*ft_get_room(t_room *head, int pos);
t_path				*ft_create_path(t_lem *lem, int *visited);
void				ft_append_path(t_path **head, t_lem *lem, int *visited);
void				ft_append_element(t_room *head, t_lem *lem, char *data);
void				ft_initial_reading(t_lem *lem, char *buff);
void				ft_process_commands(t_lem *lem, char *buff);
void				ft_swap_nodes_rooms(t_room *node_1, t_room *node_2);
void				ft_sort_path(t_path *head);
void				ft_swap_nodes_path(t_path *node_1, t_path *node_2);
void				ft_free_splitted(char **str);
void				ft_set_rooms_parameters(t_lem *lem, t_room *node);
void				ft_free_matrix(t_lem *lem);
void				ft_finish_search(t_lem *lem,
						t_path *head_path, t_room *head_room);
void				ft_add_path(t_lem *lem, t_path **path, int *vis);
void				ft_start_search(t_lem *lem, t_room *head_room, char *buff);
void				ft_handle_errors(t_lem *lem, char *buff);
void				ft_move_lem(t_lem *lem, t_path *path, t_room *head_room);
void				ft_process_first_link(t_lem *lem, t_room *head, char *buff);
void				ft_process_links(t_lem *lem, t_room *head, char *buff);
void				ft_make_matrix(t_room *head, t_lem *lem, char *buff);
void				ft_join(t_lem *lem, char *str2);
void				put_pixel_img(t_lem *lem, int x, int y, int color);
void				draw_line(t_lem *lem);
void				ft_assign_lems(t_lem *lem);
void				ft_search_parallel_paths(t_lem *lem);
void				ft_circle_simple(t_lem *lem, int x_center, int y_center);
void				ft_depth_first_search(t_lem *lem,
						t_room *head_room, int *visited, t_path **head_path);
void				ft_assign_queue(t_lem *lem, int *queue,
						int *visited, int size);
void				ft_remove_queue_elem(t_lem *lem, int *queue,
						int size, int elem);
void				ft_free_data(t_lem *lem);
int					ft_make_step(t_lem *lem, t_path *start,
						t_room *cur, uintmax_t index);
void				ft_print_lems_in_rooms(t_lem *lem, t_room *room);
void				ft_move_thread(t_lem *lem, t_path *start,
						t_room *head, uintmax_t index);
void				ft_remove_last_visited(t_lem *lem, int *visited);
void				img_clear(t_lem *lem);
void				ft_draw_nodes(t_lem *lem, t_room *head);
void				ft_draw_connections(t_lem *lem);
void				ft_free_rooms(t_room *head);
void				ft_free_path(t_path *path);
void				ft_allocate_matrix(t_lem *lem);
void				ft_print_path(t_lem *lem, t_room *head, t_path *head_path);
void				ft_print_parts(t_lem *lem, t_path *node, t_room *head);
void				ft_set_start(t_room *head);
void				ft_set_end(t_room *head);
void				ft_set_id(t_room *head);
void				ft_error(void);
void				ft_move_lem_visual(t_lem *lem,
						t_path *path, t_room *head_room);
int					ft_check_dupliactes(t_room *head);
int					ft_check_start_end(t_room *head);
int					ft_check_number(char *data);
int					ft_path_finished(t_lem *lem,
						t_room *head, const int *visited);
int					ft_get_last_visited(t_lem *lem, int *visited);
int					ft_rooms_connection(t_lem *lem, int room_1, int room_2);
int					ft_was_visited(t_lem *lem, int room, const int *visited);
int					ft_get_last_in_queue(int *queue, int size);
int					ft_list_size(t_room *head);
int					ft_count_char(char *str, char ch);
int					ft_is_comment(char *str);
int					ft_find_list_element(t_room *head, char *key);
int					get_red(int color);
int					get_green(int color);
int					get_blue(int color);
int					my_key_func(int key_code, t_lem *lem);
int					ft_draw_graph(t_lem *lem);
int					ft_visual(t_lem *lem);
int					ft_position_in_path(t_lem *lem, t_path *path, int room);
int					ft_present_room_in_path(int *path, int size, int search);

#endif
