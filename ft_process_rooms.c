/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_rooms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:19:12 by dzui              #+#    #+#             */
/*   Updated: 2017/08/11 14:19:13 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_get_room(t_room *head, int pos)
{
	t_room	*start;
	int		i;

	i = 0;
	start = head;
	while (i < pos && start->next)
	{
		start = start->next;
		i++;
	}
	return (start);
}

void	ft_append_element(t_room *head, t_lem *lem, char *data)
{
	t_room	*conductor;
	t_room	*new_node;

	conductor = head;
	while (conductor->next)
		conductor = conductor->next;
	new_node = ft_create_room(lem, data);
	conductor->next = new_node;
}

int		ft_list_size(t_room *head)
{
	t_room	*current;
	int		size;

	size = 0;
	current = head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
