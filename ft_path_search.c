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
	while (queue[0] != -1 && lem->counter < 2000)
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
