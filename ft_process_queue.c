/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:17:19 by dzui              #+#    #+#             */
/*   Updated: 2017/08/11 14:17:20 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_add_path(t_lem *lem, t_path **path, int *vis)
{
	if (*(path) == NULL)
		*(path) = ft_create_path(lem, vis);
	else
		ft_append_path(path, lem, vis);
	ft_remove_last_visited(lem, vis);
	lem->index -= 1;
	lem->counter++;
}

int		ft_get_last_in_queue(int *queue, int size)
{
	int	i;

	i = 0;
	if (queue[size - 1] != -1)
		return (queue[size - 1]);
	while (i < size - 1)
	{
		if (queue[i + 1] == -1)
			break ;
		i++;
	}
	return (queue[i]);
}

void	ft_assign_queue(t_lem *lem, int *queue, int *visited, int size)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < size)
	{
		queue[i] = -1;
		i++;
	}
	j = 0;
	k = 0;
	i = ft_get_last_visited(lem, visited);
	while (j < lem->size)
	{
		if (lem->adj_matrix[i][j] == 1 && !ft_was_visited(lem, j, visited))
		{
			queue[k] = j;
			k++;
		}
		j++;
	}
}

void	ft_remove_queue_elem(t_lem *lem, int *queue, int size, int elem)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (queue[i] == elem)
		{
			queue[i] = -1;
			break ;
		}
		i++;
	}
	while (i < lem->size - 1)
	{
		queue[i] = queue[i + 1];
		i++;
	}
}

int		ft_rooms_connection(t_lem *lem, int room_1, int room_2)
{
	if ((lem->adj_matrix[room_1][room_2] == 1) || (room_1 == room_2))
		return (1);
	return (0);
}
