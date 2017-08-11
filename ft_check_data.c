/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:16:50 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 21:16:52 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_check_dupliactes(t_room *head)
{
	t_room	*current;
	t_room	*start;

	current = head;
	while (current)
	{
		start = current->next;
		while (start)
		{
			if (ft_strequ(current->name, start->name)
				|| (current->x == start->x && current->y == start->y))
				return (0);
			start = start->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_check_start_end(t_room *head)
{
	t_room	*current;
	int		start;
	int		end;

	start = 0;
	end = 0;
	current = head;
	while (current)
	{
		if (current->start == 1)
			start = 1;
		if (current->end == 1)
			end = 1;
		current = current->next;
	}
	if (!start || !end)
		return (0);
	return (1);
}

int	ft_check_number(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (!ft_isdigit(data[i]))
			return (0);
		i++;
	}
	return (1);
}
