#include "lem_in.h"

int     ft_is_comment(char *str)
{
    int i;

    i = 0;
    while (str[i] == '#')
        i++;
    if (i == 0)
        return (0);
    return (1);
}

void    ft_make_matrix(t_room *head, t_lem *lem, char *buff)
{
    char    **splitted;
    int     i;
    int     j;

    if(ft_count_char(buff, '-') != 1)
        ft_error();
    lem->adj_matrix = (int **)malloc(sizeof(int *) * lem->size);
    i = 0;
    lem->visited = (int *)malloc(sizeof(int) * lem->size);
    while (i < lem->size)
    {
        lem->adj_matrix[i] = (int *)malloc(sizeof(int) * lem->size);
        lem->visited[i] = -1;
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
    if (i != j)
    {
        lem->adj_matrix[i][j] = 1;
        lem->adj_matrix[j][i] = 1;
    }
    ft_free_splitted(splitted);
    ft_join(lem, buff);
    free(buff);
    while (get_next_line(0, &buff))
    {
        if (ft_strequ(buff, "##start") || ft_strequ(buff, "##end") || ft_strequ(buff, "") || ft_strequ(buff, "##path"))
            ft_error();
        if (!ft_is_comment(buff))
        {
            if(ft_count_char(buff, '-') != 1)
                ft_error();
            splitted = ft_strsplit(buff, '-');
            i = ft_find_list_element(head, splitted[0]);
            j = ft_find_list_element(head, splitted[1]);
            if (i == -1 || j == -1)
                ft_error();
            if (i != j)
            {
                lem->adj_matrix[i][j] = 1;
                lem->adj_matrix[j][i] = 1;
            }
            ft_free_splitted(splitted);
            ft_join(lem, buff);
        }
        free(buff);
    }
    free(buff);
}