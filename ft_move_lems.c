/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_lems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:15:29 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 21:15:32 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*ft_where_the_ant_is(t_room *head, uintmax_t active_lem)
{
	t_room	*start;

	start = head;
	while (start)
	{
		if (active_lem == start->active_lem)
			return (start);
		start = start->next;
	}
	return (head);
}

int			ft_position_in_path(t_lem *lem, t_path *path, int room)
{
	int	i;

	i = 0;
	while (i < lem->size && path->path[i] != -1)
	{
		if (path->path[i] == room)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_make_step(t_lem *lem, t_path *start,
				t_room *cur, uintmax_t index)
{
	t_room	*next_room;
	int		pos;

	pos = ft_position_in_path(lem, start, cur->id);
	if (pos != -1)
	{
		next_room = ft_get_room(lem->head, start->path[pos + 1]);
		if (next_room->active_lem == 0)
		{
			cur->active_lem = 0;
			if (next_room->id != lem->size - 1)
				next_room->active_lem = index + 1;
			else
			{
				lem->lems[index] = -1;
				lem->ants--;
			}
			if (!lem->visual)
				ft_printf("L%d-%s ", index + 1, next_room->name);
			return (1);
		}
	}
	return (0);
}

void		ft_move_lem_visual(t_lem *lem, t_path *path, t_room *head_room)
{
	uintmax_t	index;
	t_path		*start;

	index = 0;
	while (index < lem->init)
	{
		lem->flag = 0;
		if (lem->lems[index] != -1)
		{
			start = path;
			ft_move_thread(lem, start, head_room, index);
			if (!lem->flag)
				break ;
		}
		index++;
	}
}

void		ft_move_lem(t_lem *lem, t_path *path, t_room *head_room)
{
	uintmax_t	index;
	t_path		*start;

	while (lem->ants > 0)
	{
		index = 0;
		while (index < lem->init)
		{
			lem->flag = 0;
			if (lem->lems[index] != -1)
			{
				start = path;
				ft_move_thread(lem, start, head_room, index);
				if (!lem->flag)
					break ;
			}
			index++;
		}
		if (!lem->visual)
			ft_printf("\n");
	}
}
