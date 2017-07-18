#include "lem_in.h"

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