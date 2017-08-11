/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:08:07 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 21:08:08 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

void	ft_depth_first_search(t_lem *lem, t_room *head, int *vis, t_path **path)
{
	int current;
	int next;
	int queue[lem->size];

	if (ft_path_finished(lem, head, vis))
	{
		ft_add_path(lem, path, vis);
		return ;
	}
	ft_assign_queue(lem, queue, vis, lem->size);
	while (queue[0] != -1 && lem->counter < 1000)
	{
		current = ft_get_last_visited(lem, vis);
		next = ft_get_last_in_queue(queue, lem->size);
		if (ft_rooms_connection(lem, current, next)
			&& !ft_was_visited(lem, next, vis))
		{
			vis[lem->index] = next;
			lem->index++;
			ft_remove_queue_elem(lem, queue, lem->size, next);
			ft_depth_first_search(lem, lem->head, vis, path);
		}
	}
	ft_remove_last_visited(lem, vis);
	lem->index -= 1;
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

int		ft_was_visited(t_lem *lem, int room, const int *visited)
{
	int i;

	i = 0;
	while (i < lem->size)
	{
		if (visited[i] == room)
			return (1);
		i++;
	}
	return (0);
}

void	ft_remove_last_visited(t_lem *lem, int *visited)
{
	int i;

	if (visited[lem->size - 1] != -1)
	{
		visited[lem->size - 1] = -1;
		return ;
	}
	i = 0;
	while (i < lem->size - 1)
	{
		if (visited[i + 1] == -1)
			break ;
		i++;
	}
	visited[i] = -1;
}

int		ft_get_last_visited(t_lem *lem, int *visited)
{
	int i;

	if (visited[lem->size - 1] != -1)
		return (visited[lem->size - 1]);
	i = 0;
	while (i < lem->size - 1)
	{
		if (lem->visited[i + 1] == -1)
			return (lem->visited[i]);
		i++;
	}
	return (-2);
}

int		ft_path_finished(t_lem *lem, t_room *head, const int *visited)
{
	int i;
	int id;

	i = 0;
	id = (ft_get_room(head, lem->size - 1))->id;
	while (i < lem->size)
	{
		if (visited[i] == id)
			return (1);
		i++;
	}
	return (0);
}
