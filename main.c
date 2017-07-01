#include "lem_in.h"



int     main(void)
{
    t_lem   lem;
    t_room  *head_room;
    t_path  *head_path;

    head_room = NULL;
    head_path = NULL;
    lem.input_data = ft_strnew(0);
    lem.start = 0;
    lem.end = 0;
    while (get_next_line(0, &lem.input_data)
           && lem.input_data[0] == '#')
    {
        if (ft_strequ(lem.input_data, "##start")
                || ft_strequ(lem.input_data, "##end"))
            ft_error();
    }
    if (!ft_check_number(lem.input_data) || ft_strequ(lem.input_data, ""))
        ft_error();
    lem.ants = ft_atoi_unsigned(lem.input_data);
    while (get_next_line(0, &lem.input_data))
    {
        if (lem.input_data == NULL)
            ft_error();
        if (ft_count_char(lem.input_data, '-') == 1 && !ft_count_char(lem.input_data, ' '))
            break ;
        if (ft_strequ(lem.input_data, ""))
            ft_error();
        if ((lem.input_data[0] == '#' && lem.input_data[1] && lem.input_data[1] != '#')
            || ((lem.input_data[0] == '#' && lem.input_data[1] && lem.input_data[1] == '#')
                && !ft_strequ(lem.input_data, "##start") && !ft_strequ(lem.input_data, "##end")))
            continue ;
        if (ft_strequ(lem.input_data, "##start") && lem.start)
            ft_error();
        if (ft_strequ(lem.input_data, "##start") && lem.start == 0)
        {
            ft_strclr(lem.input_data);
            while (get_next_line(0, &lem.input_data))
            {
                if ((lem.input_data[0] == '#' && lem.input_data[1] && lem.input_data[1] != '#'))
                    continue ;
                else if (((lem.input_data[0] == '#' && lem.input_data[1] && lem.input_data[1] == '#')
                          && !ft_strequ(lem.input_data, "##start") && !ft_strequ(lem.input_data, "##end")))
                    continue ;
                else if (((lem.input_data[0] == '#' && lem.input_data[1] && lem.input_data[1] == '#')
                          && (ft_strequ(lem.input_data, "##start") || ft_strequ(lem.input_data, "##end"))))
                    ft_error();
                else if (ft_strequ(lem.input_data, ""))
                    ft_error();
                else
                    break ;
            }
            lem.start = 1;
        }
        if (ft_strequ(lem.input_data, "##end") && lem.end)
            ft_error();
        if (ft_strequ(lem.input_data, "##end") && lem.end == 0)
        {
            ft_strclr(lem.input_data);
            while (get_next_line(0, &lem.input_data))
            {
                if ((lem.input_data[0] == '#' && lem.input_data[1] && lem.input_data[1] != '#'))
                    continue ;
                else if (((lem.input_data[0] == '#' && lem.input_data[1] && lem.input_data[1] == '#')
                          && !ft_strequ(lem.input_data, "##start") && !ft_strequ(lem.input_data, "##end")))
                    continue ;
                else if (((lem.input_data[0] == '#' && lem.input_data[1] && lem.input_data[1] == '#')
                          && (ft_strequ(lem.input_data, "##start") || ft_strequ(lem.input_data, "##end"))))
                    ft_error();
                else if (ft_strequ(lem.input_data, ""))
                    ft_error();
                else
                    break ;
            }
            lem.end = 1;
        }
        if (head_room == NULL)
            head_room = ft_create_room(&lem);
        else
            ft_append_element(head_room, &lem);
        ft_strclr(lem.input_data);
    }
    if (!ft_check_dupliactes(head_room))
        ft_error();
    if (!ft_check_start_end(head_room))
        ft_error();
    ft_set_start(head_room);
    ft_set_end(head_room);
    ft_sort_rooms(head_room);
    lem.size = ft_list_size(head_room);
    ft_make_matrix(head_room, &lem);
    int counter;
    counter = 0;
    while (ft_present_path(&lem))
    {
        lem.found = 0;
        ft_depth_first_search(&lem, 0, head_room);
       if (head_path == NULL)
           head_path = ft_create_path(&lem);
       else
       {
       		t_path *kek = ft_append_path(head_path, &lem);
       }
        ft_clear_path(&lem);
        counter++;
    }
    if (counter == 0)
        ft_error();
   ft_printf("\n");
   ft_sort_path(head_path);
   ft_print_list(head_path, &lem);
    return (0);
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

void    ft_depth_first_search(t_lem *lem, int i, t_room *head_room)
{
    int j;
    int temp;

    j = i;
    lem->visited[j] = 1;
    if (j == lem->size - 1 && lem->visited[j])
    {
        lem->adj_matrix[lem->prev_i][lem->prev_j] = -1;
        lem->adj_matrix[lem->prev_j][lem->prev_i] = -1;
        lem->found = 1;
    }
    while (j < lem->size && !lem->found)
    {
        if (lem->adj_matrix[i][j] == -1 )
        {
        	temp = ft_check_connection(lem, i, j);
        	if (temp >= 0)
        		j = temp;
        	else
        	{
        		lem->adj_matrix[lem->prev_i][lem->prev_j] = -1;
            	lem->adj_matrix[lem->prev_j][lem->prev_i] = -1;
            	lem->visited[i] = 0;
            	ft_clear_path(lem);
            	ft_depth_first_search(lem, 0, head_room);
        	}
        }
        if (!lem->visited[j] && lem->adj_matrix[i][j] == 1)
        {
            lem->prev_i = i;
            lem->prev_j = j;
            ft_depth_first_search(lem, j, head_room);
        }
        j++;
    }
}

int 	ft_check_connection(t_lem *lem, int i, int j)
{
	while (j < lem->size)
	{
		if (lem->adj_matrix[i][j] == 1)
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
        if (lem->adj_matrix[i][j] == 1)
            return (1);
        i++;
    }
    return (0);
}