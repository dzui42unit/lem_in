#include "lem_in.h"

char 	*ft_join(const char *str1, const char *str2)
{
	char *res;

	res = (char *)malloc((2 + ft_strlen(str1) + ft_strlen(str2)) * sizeof(char));
	ft_strcpy(res, str1);
	ft_strcat(res, str2);
	ft_strcat(res, "\n");
	return (res);
}

int     main(void)
{
    t_lem   lem;
    t_room  *head_room;
    t_path  *head_path;
    char 	*buff;

    head_room = NULL;
    head_path = NULL;
    buff = ft_strnew(1);
    lem.input_data = ft_strnew(1);
    lem.start = 0;
    lem.end = 0;
	lem.show_path = 0;
    while (get_next_line(0, &buff) && buff[0] == '#')
    {
    	if (ft_strequ(buff, "##start") || ft_strequ(buff, "##end") || ft_strequ(buff, "##path"))
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
    	{
    		ft_error();
    	}
    	if (ft_strequ(buff, "") || start > 1 || end > 1)
    	{
    		ft_error();
    	}
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
    ft_set_id(head_room);
    ft_printf("\n");
    lem.size = ft_list_size(head_room);
    lem.que_size = lem.size * lem.size;
    ft_make_matrix(head_room, &lem, buff);
    lem.head = head_room;
    ft_printf("%s", lem.input_data);
    ft_print_rooms(head_room);
    lem.visited[0] = (ft_get_room(head_room, 0))->id;
    lem.index = 1;
    ft_depth_first_search(&lem, head_room, lem.visited);
	return (0);
}
