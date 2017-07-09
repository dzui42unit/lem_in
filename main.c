#include "lem_in.h"

int     main(void)
{
    t_lem   lem;
    t_room  *head_room;
    t_path  *head_path;
    char 	*buff;

    head_room = NULL;
    head_path = NULL;
    buff = ft_strnew(0);
    lem.start = 0;
    lem.end = 0;
    while (get_next_line(0, &buff) && buff[0] == '#')
    {
    	if (ft_strequ(buff, "##start") || ft_strequ(buff, "##end"))
    		ft_error();
    	ft_strclr(buff);
    }
    if (!ft_check_number(buff) || ft_strequ(buff, ""))
    	ft_error();
    lem.ants = ft_atoi_unsigned(buff);
    ft_strclr(buff);
    int start = 0;
    int end = 0;
    while (get_next_line(0, &buff))
    {
    	if (ft_count_char(buff, '-') == 1 && buff[0] != '-')
    	{
    		break ;
    	}
    	if (ft_count_char(buff, '-') > 1 || buff[0] == '-')
    	{
    		ft_error();
    	}
    	if (ft_strequ(buff, "") || start > 1 || end > 1)
    	{
    		ft_error();
    	}
    	if (buff[0] == '#' && ft_count_char(buff, '#') == 1)
    	{
    		ft_strclr(buff);
    		continue ;
    	}
    	if (buff[0] == '#' && ft_strequ(buff, "##start"))
    	{
    		start++;
    		lem.start = start;
    		ft_strclr(buff);
    		continue ;
    	}
    	if (buff[0] == '#' && ft_strequ(buff, "##end"))
    	{
    		end++;
    		lem.end = end;
    		ft_strclr(buff);
    		continue ;
    	}
    	if (head_room == NULL)
           	head_room = ft_create_room(&lem, buff);
        else
           	ft_append_element(head_room, &lem, buff);
       	ft_strclr(buff);
    }
    if (!ft_check_dupliactes(head_room))
        ft_error();
    if (!ft_check_start_end(head_room))
        ft_error();
    ft_set_start(head_room);
    ft_set_end(head_room);
    ft_sort_rooms(head_room);
    lem.size = ft_list_size(head_room);
    ft_make_matrix(head_room, &lem, buff);
    ft_connection_numbers(&lem);
    int counter;
    counter = 0;
    int i = 0;
   	lem.head = head_room;
   	ft_draw_graph(&lem);
    ft_cut_nodes(&lem);
    while (ft_present_path(&lem))
    {
    	if (i >= 500)
    		break ;
        lem.found = 0;
        ft_depth_first_search(&lem, 0, head_room);
       	if (head_path == NULL)
           head_path = ft_create_path(&lem);
       	else
       		ft_append_path(head_path, &lem);
       	ft_clear_path(&lem);
       	counter++;
       	i++;
    }
    if (counter == 0)
        ft_error();
   ft_printf("\n");
   ft_sort_path(head_path);
   ft_print_path(&lem, head_room, head_path);
   return (0);
}

int 	ft_visual(t_lem *lem)
{
	t_room *start;
	int 	x;
	int 	y;

	img_clear(lem);
	start = lem->head;
	while (start)
	{
		x = start->x;
		y = start->y;
		circleSimple(lem, x, y, 30, 0x00FFFFFF);
		start = start->next;
	}
	int i;
	int j;
	t_room *end;

	i = 0;
	while (i < lem->size)
	{
		j = 0;
		while (j < lem->size)
		{
			if (lem->adj_matrix[i][j] == 1)
			{
				start = ft_get_room(lem->head, i);
				end = ft_get_room(lem->head, j);
				draw_line(lem, start->x, start->y, end->x, end->y);
			}
			j++;
		}
		i++;
	}
	start = lem->head;
	mlx_put_image_to_window(lem->mlx, lem->win, lem->image, 0, 0);
	while (start)
	{
		mlx_string_put(lem->mlx, lem->win, start->x, start->y, 0x00FF00FF, start->name);
		start = start->next;
	}
	return (0);
}

void	ft_connection_numbers(t_lem *lem)
{
	int i;
	int j;
	int temp;

	i = 1;
	j = lem->size - 1;
	while (i < lem->size)
	{
		if (lem->adj_matrix[i][j] == 1)
		{
			temp = ft_assign_last(lem, i);
			lem ->adj_matrix[i][j] = temp;
		}
		i++;
	}
}

int 	ft_assign_last(t_lem *lem, int i)
{
	int j;
	int counter;

	j = 0;
	counter = 0;
	while (j < i)
	{
		if (lem->adj_matrix[i][j] == 1)
			counter++;
		j++;
	}
	return (counter);
}

void 	ft_cut_nodes(t_lem *lem)
{
	int i;
	int j;
	int connect_1;
	int connect_2;

	i = 0;
	connect_1 = 0;
	connect_2 = 0;
	while (i < lem->size)
	{
		connect_1 = ft_check_prev(lem, i);
		connect_2 = ft_check_next(lem, i);
		if ((connect_2 == 0 || connect_1 == 0) && !ft_is_empty(lem, i))
		{
			ft_erase_node(lem, i);
			ft_cut_nodes(lem);
		}
		i++;
	}
}

int 	ft_is_empty(t_lem *lem, int i)
{
	int j;

	j = 0;
	while (j < lem->size)
	{
		if (lem->adj_matrix[i][j] > 0)
			return (0);
		j++;
	}
	return (1);
}

void	ft_erase_node(t_lem *lem, int i)
{
	int j;

	j = 0;
	while (j < lem->size)
	{
		lem->adj_matrix[i][j] = 0;
		j++;
	}
	j = i;
	i = 0;
	while (i < lem->size)
	{
		lem->adj_matrix[i][j] = 0;
		i++;
	}
}

int 	ft_check_prev(t_lem *lem, int i)
{
	int j;
	int counter;

	j = 0;
	if (i == 0)
		return (1);
	counter = 0;
	while (j < i)
	{
		if (lem->adj_matrix[i][j] > 0)
			counter++;
		j++;
	}
	return (counter);
}

int 	ft_check_next(t_lem *lem, int i)
{
	int j;
	int counter;

	j = i;
	counter = 0;
	if (j == lem->size - 1)
		return (1);
	while (j < lem->size)
	{
		if (lem->adj_matrix[i][j] > 0)
			counter++;
		j++;
	}
	return (counter);
}

void    ft_clear_path(t_lem *lem)
{
    int i;

    i = 0;
    while (i < lem->size)
    {
        lem->visited[i] = 0;
        i++;
    }
}

void	ft_find_prev_node(t_lem *lem)
{
	int i;
	int j;

	i = lem->size - 2;
	while (i >= 0)
	{
		if (lem->visited[i] == 1)
		{
			break ;
		}
		i--;
	}
	j = lem->size - 2;
	while (j >= 0)
	{
		if (lem->adj_matrix[i][j] == 1)
		{
			lem->adj_matrix[i][j] = -1;
			lem->adj_matrix[j][i] = -1;
			return ;
		}
		j--;
	}
}

void    ft_depth_first_search(t_lem *lem, int i, t_room *head_room)
{
    int j;
    int temp;

    j = i;
    lem->visited[j] = 1;
    if (j == lem->size - 1 && lem->visited[j])
    {
        lem->adj_matrix[lem->prev_i][lem->prev_j]--;
        lem->adj_matrix[lem->prev_j][lem->prev_i]--;
        if (lem->adj_matrix[lem->prev_i][lem->prev_j] == 0)
        {
			lem->adj_matrix[lem->prev_i][lem->prev_j] = -1;
        	lem->adj_matrix[lem->prev_j][lem->prev_i] = -1;
        }
        else
        {
        	ft_find_prev_node(lem);
        }
        lem->found = 1;
    }
    while (j < lem->size && !lem->found)
    {
        if (lem->adj_matrix[i][j] == -1)
        {
        	temp = ft_check_connection(lem, i, j);
        	if (temp != -1)
        		j = temp;
        	else
        	{
		        lem->adj_matrix[lem->prev_i][lem->prev_j] = -1;
		        lem->adj_matrix[lem->prev_j][lem->prev_i] = -1;
            	ft_clear_path(lem);
            	ft_depth_first_search(lem, 0, head_room);
        	}
        }
        if (!lem->visited[j] && lem->adj_matrix[i][j] > 0)
        {
            lem->prev_i = i;
            lem->prev_j = j;
            ft_depth_first_search(lem, j, head_room);
        }
        j++;
    }
}

void	ft_print_path(t_lem *lem, t_room *head, t_path *head_path)
{
	int 	i;
	int 	j;
	int 	counter;
	t_path 	*current;

	counter = 0;
	current = head_path;
	while (current)
	{
		i = 0;
		j = 0;
		ft_printf("path #%d\n", counter + 1);
		while (i < lem->size)
		{
			if (current->path[i] == 1)
			{
				ft_print_needed_node(lem, head, i);
				if (j < current->length - 1)
				{
					ft_printf(" -> ");
					j++;
				}
			}
			i++;
		}
		counter++;
		current = current->next;
		ft_printf("\n");
	}
	ft_printf("\n");
}

int 	ft_check_connection(t_lem *lem, int i, int j)
{
	while (j < lem->size)
	{
		if (lem->adj_matrix[i][j] > 0)
			return (j);
		j++;
	}
	return (-1);
}

int     ft_present_path(t_lem *lem)
{
    int i;
    int j;

    i = 0;
    j = lem->size - 1;
    while (i < lem->size)
    {
        if (lem->adj_matrix[i][j] > 0)
            return (1);
        i++;
    }
    return (0);
}

