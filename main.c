#include "lem_in.h"

int     ft_comment(char *str)
{
    int i;

    i = 0;
    while (str[i] == '#')
        i++;
    if (i == 2)
        return (0);
    return (1);
}

int     main(void)
{
    t_lem   lem;
    t_room  *head_room;
    t_path  *head_path;
    char 	*buff;
    char 	*temp;

    head_room = NULL;
    head_path = NULL;
    buff = ft_strnew(1);
    lem.input_data = ft_strnew(1);
    lem.start = 0;
    lem.end = 0;
	lem.show_path = 0;
    while (get_next_line(0, &buff) && buff[0] == '#')
    {
        if (!ft_comment(buff))
    		ft_error();
    	ft_strclr(buff);
    }
    if (!ft_check_number(buff) || ft_strequ(buff, ""))
    	ft_error();
    lem.ants = ft_atoi_unsigned(buff);
    lem.input_data = ft_join(lem.input_data, buff);
    ft_strclr(buff);
    int start = 0;
    int end = 0;
    while (get_next_line(0, &buff))
    {
    	if (ft_count_char(buff, '-') == 1 && buff[0] != '-')
    	{
    		lem.input_data = ft_join(lem.input_data, buff);
    		break ;
    	}
    	if (ft_count_char(buff, '-') > 1 || buff[0] == '-')
    		ft_error();
    	if (ft_strequ(buff, "") || start > 1 || end > 1)
    		ft_error();
    	if (ft_strequ(buff, "##start"))
    	{
    		lem.input_data = ft_join(lem.input_data, buff);
    		start++;
    		lem.start = start;
    		ft_strclr(buff);
    		continue ;
    	}
    	if (ft_strequ(buff, "##end"))
    	{
    		end++;
    		lem.end = end;
    		lem.input_data = ft_join(lem.input_data, buff);
    		ft_strclr(buff);
    		continue ;
    	}
		if (ft_strequ(buff, "##path"))
		{
			lem.show_path = 1;
			ft_strclr(buff);
			continue ;
		}
		if (buff[0] == '#')
		{
			ft_strclr(buff);
			continue ;
		}
		lem.input_data = ft_join(lem.input_data, buff);
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
    lem.size = ft_list_size(head_room);
    ft_make_matrix(head_room, &lem, buff);
    ft_cut_nodes(&lem);
    int counter;
    counter = 0;
   	lem.head = head_room;
   	while (ft_present_path(&lem))
   	{
        lem.found = 0;
        ft_depth_first_search(&lem, 0, head_room);
      	if (head_path == NULL)
          head_path = ft_create_path(&lem);
      	else
      		ft_append_path(head_path, &lem);
       	ft_clear_path(&lem);
      	counter++;
   	}
   	if (counter == 0)
       ft_error();
	ft_sort_path(head_path);
	ft_printf("\n%s", lem.input_data);
	ft_printf("\n");
	ft_print_path(&lem, head_room, head_path);
	return (0);
}

void    ft_restore_connections(t_lem *lem)
{
    int i;
    int j;
    int flag;

    i = 1;
    while (i < lem->size - 1)
    {
        flag = 0;
        if (lem->visited[i] == 1)
        {
            j = i + 1;
            while (j < lem->size - 1)
            {
                if (lem->visited[j] == 1)
                {
                    flag = 1;
                    break ;
                }
                j++;
            }
        }
        if (flag)
        {
            if (ft_check_connect(lem, i))
            {
                lem->adj_matrix[i][j] = 1;
                lem->adj_matrix[j][i] = 1;
            }
            i = j;
        }
        else
            i++;
    }
}

int     ft_check_path_presense(t_lem *lem)
{
    int i;
    int j;

    i = 0;
    while (i < lem->size)
    {
        j = 0;
        while (j < lem->size)
        {
            if (lem->adj_matrix[i][j] == 1)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int     ft_check_connect(t_lem *lem, int i)
{
    int j;
    int counter;

    j = i + 1;
    counter = 0;
    while (i < lem->size)
    {
        if (lem->adj_matrix[i][j] > 0)
            counter++;
        i++;
    }
    if (counter == 0)
        return (0);
    return (1);
}
