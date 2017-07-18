#include "lem_in.h"

void    ft_make_matrix(t_room *head, t_lem *lem, char *buff)
{
    char    **splitted;
    int     i;
    int     j;

    if(ft_count_char(buff, '-') != 1)
        ft_error();
    lem->adj_matrix = (int **)malloc(sizeof(int *) * lem->size);
    lem->init = (int **)malloc(sizeof(int *) * lem->size);
    i = 0;
    lem->visited = (int *)malloc(sizeof(int) * lem->size);
    while (i < lem->size)
    {
        lem->adj_matrix[i] = (int *)malloc(sizeof(int) * lem->size);
        lem->init[i] = (int *)malloc(sizeof(int) * lem->size);
        lem->visited[i] = 0;
        i++;
    }
    i = 0;
    while (i < lem->size)
    {
        j = 0;
        while (j < lem->size)
        {
            lem->adj_matrix[i][j] = 0;
            j++;
        }
        i++;
    }
    splitted = ft_strsplit(buff, '-');
    i = ft_find_list_element(head, splitted[0]);
    j = ft_find_list_element(head, splitted[1]);
    if (i == -1 || j == -1)
        ft_error();
    lem->adj_matrix[i][j] = 1;
    lem->adj_matrix[j][i] = 1;
    while (get_next_line(0, &buff))
    {
        if (ft_strequ(buff, "##start") || ft_strequ(buff, "##end") || ft_strequ(buff, ""))
            ft_error();
        if (ft_strequ(buff, "##path"))
        {
            lem->show_path = 1;
            ft_strclr(buff);
            continue ;
        }
        if (buff[0] == '#')
        {
            ft_strclr(buff);
            continue ;
        }
        if(ft_count_char(buff, '-') != 1)
            ft_error();
        splitted = ft_strsplit(buff, '-');
        i = ft_find_list_element(head, splitted[0]);
        j = ft_find_list_element(head, splitted[1]);
        ft_printf("Room 1: %s, index = %d\n", splitted[0], i);
        ft_printf("Room 2: %s, index = %d\n", splitted[1], j);
        if (i == -1 || j == -1)
            ft_error();
        if (i == j)
            lem->adj_matrix[i][j] = 0;
        else
        {
            lem->adj_matrix[i][j] = 1;
            lem->adj_matrix[j][i] = 1;
        }
        lem->input_data = ft_join(lem->input_data, buff);
        ft_strclr(buff);
    }
    ft_copy_matrix(lem);
}

void    ft_copy_matrix(t_lem *lem)
{
    int i;
    int j;

    i = 0;
    while (i < lem->size)
    {
        j = 0;
        while (j < lem->size)
        {
            lem->init[i][j] = lem->adj_matrix[i][j];
            j++;
        }
        i++;
    }
}