#include "lem_in.h"

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

void 	ft_cut_nodes(t_lem *lem)
{
	int i;
	int j;
	int connect;

	i = 0;
	connect = 0;
	while (i < lem->size)
	{
		connect = ft_check_prev(lem, i);
		if (connect == 0 && !ft_is_empty(lem, i))
		{
			ft_erase_node(lem, i);
			ft_cut_nodes(lem);
		}
		i++;
	}
}