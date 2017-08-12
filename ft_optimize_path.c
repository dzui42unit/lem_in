/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimize_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 13:24:10 by dzui              #+#    #+#             */
/*   Updated: 2017/08/12 13:24:11 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_assign_lems(t_lem *lem)
{
	uintmax_t i;

	i = 0;
	lem->lems = (int *)malloc(sizeof(int) * lem->ants);
	while (i < lem->ants)
	{
		lem->lems[i] = 1;
		i++;
	}
}

void	ft_delete_path(t_path **path, t_path **current)
{
	t_path *prev;
	t_path *head;

	head = *path;
	if (head == *current)
	{
		if (head == NULL)
			return ;
		head->path = head->next->path;
		head->next = head->next->next;
		free((*current)->path);
		free((*current));
		return ;
	}
	prev = *path;
	while (prev->next && prev->next != *current)
		prev = prev->next;
	if (prev->next == NULL)
		return ;
	prev->next = prev->next->next;
	free((*current)->path);
	free((*current));
	return ;
}

int		ft_present_room_in_path(int *path, int size, int search)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (path[i] == search)
			return (1);
		i++;
	}
	return (0);
}

void	ft_search_parallel_paths(t_lem *lem)
{
	t_path	*st;
	t_path	*go;
	int		i;

	st = lem->path;
	while (st)
	{
		i = 1;
		while (i < lem->size && st->path[i] != -1)
		{
			if (st->path[i] == lem->size - 1)
				break ;
			go = st->next;
			if (go == NULL)
				break ;
			while (go)
			{
				if (ft_present_room_in_path(go->path, lem->size, st->path[i]))
					ft_delete_path(&(lem->path), &(go));
				go = go->next;
			}
			i++;
		}
		st = st->next;
	}
}
