#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H
# include "get_next_line.h"
# include <stdlib.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <limits.h>
# include <unistd.h>
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# define WIDTH 1920
# define HEIGHT 1080

typedef struct      s_room
{
    struct s_room   *next;
    uintmax_t       x;
    uintmax_t       y;
    char            *name;
    int             end;
    int             start;
}                   t_room;

typedef struct      s_path
{
    struct s_path   *next;
    int             *path;
    int             length;
}                   t_path;

typedef struct      s_lem
{
    t_room          *head;
    uintmax_t       ants;
    void            *mlx;
    void            *win;
    void            *image;
    char            *input_data;
    int             **lems;
    int             start;
    int             **adj_matrix;
    int 			**init;
    int             end;
    int             size;
    int             *visited;
    int             found;
    int             radius;
    int             prev_i;
    int             prev_j;
    int 			del;
	int				show_path;
    int             active_lem;
    int             turn;
}                   t_lem;

void            ft_find_prev_list_node(t_room **head, t_room **node, t_room **assign);
void            ft_swap_nodes_rooms(t_room **head, t_room **first, t_room **second);
int             ft_check_path_presense(t_lem *lem);
t_room          *ft_create_room(t_lem *lem, char *data);
t_room          *ft_append_element(t_room *head, t_lem *lem, char *data);
t_room          *ft_get_room(t_room *head, int pos);
t_path          *ft_create_path(t_lem *lem);
t_path          *ft_append_path(t_path *head, t_lem *lem);
uintmax_t       ft_atoi_unsigned(char *str);
void            ft_make_matrix(t_room *head, t_lem *lem, char *buff);
void            ft_print_adjecency_matrix(t_lem *lem);
void            ft_sort_rooms(t_room *head);
void            ft_restore_connections(t_lem *lem);
void            ft_set_start(t_room *head);
void            ft_set_end(t_room *head);
void            ft_depth_first_search(t_lem *lem, int i, t_room *head);
void            ft_print_list(t_path *head, t_lem *lem);
void            ft_swap_nodes_path(t_path *node_1, t_path *node_2);
void            ft_sort_path(t_path *head);
void            ft_print_needed_node(t_lem *lem, t_room *head, int pos);
void            ft_clear_path(t_lem *lem);
void            ft_erase_node(t_lem *lem, int i);
void            ft_set_last_row(t_lem *lem);
void            ft_count_path(t_lem *lem);
void            ft_connection_numbers(t_lem *lem);
void            ft_find_prev_node(t_lem *lem);
void            ft_print_path(t_lem *lem, t_room *head, t_path *head_path);
void            put_pixel_img(t_lem *lem, int x, int y, int color);
void            draw_line(t_lem *lem, int x1, int y1, int x2, int y2);
void            circleSimple(t_lem *lem, int xCenter, int yCenter, int color);
void            ft_move_lem(t_lem *lem, t_path *path, t_room *head_room);
void            img_clear(t_lem *lem);
void            ft_copy_matrix(t_lem *lem);
void            ft_cut_nodes(t_lem *lem);
void            ft_error();
char            *ft_join(const char *str1, const char *str2);
int             ft_comment(char *str);
int             ft_check_connect(t_lem *lem, int i);
int             ft_check_number(char *data);
int             ft_count_char(char *str, char ch);
int             ft_find_list_element(t_room *head, char *key);
int             ft_list_size(t_room *head);
int             ft_check_dupliactes(t_room *head);
int             ft_check_start_end(t_room *head);
int             ft_string_compare(char *str_1, char *str_2);
int             ft_present_path(t_lem *lem);
int 			ft_check_connection(t_lem *lem, int i, int j);
int 			ft_check_prev(t_lem *lem, int i);
int 			ft_check_next(t_lem *lem, int i);
int 			ft_is_empty(t_lem *lem, int i);
int 			ft_assign_last(t_lem *lem, int i);
int 			ft_check_dupliactes_path(t_lem *lem,  t_path *head);
int				get_red(int color);
int				get_green(int color);
int				get_blue(int color);
int				my_key_func(int key_code, t_lem *lem);
int 			ft_visual(t_lem *lem);
int				ft_draw_graph(t_lem *lem);
int             ft_find_room(t_lem *lem, t_path *way, int active_lem);
int             ft_is_free_room(t_lem *lem, int nb_room, int lems);
int				ft_has_connected_node(t_lem *lem, int i);
void            ft_set_start_end(t_room **head);

#endif
