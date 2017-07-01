#include "lem_in.h"

void    ft_make_matrix(t_room *head, t_lem *lem)
{
    char    **splitted;
    int     i;
    int     j;

    if(ft_count_char(lem->input_data, '-') != 1)
        ft_error();
    lem->adj_matrix = (int **)malloc(sizeof(int *) * lem->size);
    i = 0;
    lem->visited = (int *)malloc(sizeof(int) * lem->size);
    while (i < lem->size)
    {
        lem->adj_matrix[i] = (int *)malloc(sizeof(int) * lem->size);
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
    splitted = ft_strsplit(lem->input_data, '-');
    i = ft_find_list_element(head, splitted[0]);
    j = ft_find_list_element(head, splitted[1]);
    if (i == -1 || j == -1)
        ft_error();
    lem->adj_matrix[i][j] = 1;
    lem->adj_matrix[j][i] = 1;
    while (get_next_line(0, &lem->input_data))
    {
        if(ft_count_char(lem->input_data, '-') != 1)
            ft_error();
        splitted = ft_strsplit(lem->input_data, '-');
        i = ft_find_list_element(head, splitted[0]);
        j = ft_find_list_element(head, splitted[1]);
        if (i == -1 || j == -1)
            ft_error();
        lem->adj_matrix[i][j] = 1;
        lem->adj_matrix[j][i] = 1;
    }
}