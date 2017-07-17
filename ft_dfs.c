#include "lem_in.h"

void    ft_depth_first_search(t_lem *lem, int i, t_room *head_room)
{
	int j;
	int temp;
	
	j = i;
	lem->visited[j] = 1;
	if (j == lem->size - 1)
	{
		lem->adj_matrix[lem->prev_i][lem->prev_j]--;
		lem->adj_matrix[lem->prev_j][lem->prev_i]--;
		lem->found = 1;
	}
	while (j < lem->size && !lem->found)
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
		if (!lem->visited[j] && lem->adj_matrix[i][j] > 0)
		{
			lem->prev_i = i;
			lem->prev_j = j;
			ft_depth_first_search(lem, j, head_room);
		}
		j++;
	}
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

int		ft_has_connected_node(t_lem *lem, int i)
{
	int j;
	
	j = 0;
	while (j < i)
	{
		if (lem->adj_matrix[i][j] == 1)
			return (1);
		j++;
	}
	return (0);
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