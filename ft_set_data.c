/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_Data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:35:45 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 20:35:47 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_set_start(t_room *head)
{
	t_room *current;

	current = head;
	while (current->next)
	{
		if (current->start)
			break ;
		current = current->next;
	}
	if (current != head)
		ft_swap_nodes_rooms(head, current);
}

void	ft_set_end(t_room *head)
{
	t_room *current;
	t_room *end;

	current = head;
	end = head;
	while (current->next)
	{
		if (current->end)
			break ;
		current = current->next;
	}
	while (end->next)
		end = end->next;
	ft_swap_nodes_rooms(current, end);
}

void	ft_set_id(t_room *head)
{
	t_room	*start;
	int		id;

	id = 0;
	start = head;
	while (start)
	{
		start->id = id;
		id++;
		start = start->next;
	}
}
