/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:51:35 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 20:51:37 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_find_list_element(t_room *head, char *key)
{
	t_room	*start;
	int		i;

	i = 0;
	start = head;
	while (start)
	{
		if (ft_strequ(start->name, key))
			return (i);
		start = start->next;
		i++;
	}
	return (-1);
}

void	ft_swap_nodes_rooms(t_room *node_1, t_room *node_2)
{
	t_room	*temp;

	temp = (t_room *)malloc(sizeof(t_room));
	temp->x = node_1->x;
	temp->y = node_1->y;
	temp->start = node_1->start;
	temp->end = node_1->end;
	temp->name = node_1->name;
	node_1->name = node_2->name;
	node_1->x = node_2->x;
	node_1->y = node_2->y;
	node_1->start = node_2->start;
	node_1->end = node_2->end;
	node_2->name = temp->name;
	node_2->x = temp->x;
	node_2->y = temp->y;
	node_2->start = temp->start;
	node_2->end = temp->end;
	free(temp);
}

void	ft_set_rooms_parameters(t_lem *lem, t_room *node)
{
	node->next = NULL;
	if (lem->start == 1)
	{
		node->start = 1;
		node->end = 0;
		lem->start = 0;
	}
	else if (lem->end == 1)
	{
		node->start = 0;
		node->end = 1;
		lem->end = 0;
	}
	else
	{
		node->start = 0;
		node->end = 0;
	}
	node->active_lem = 0;
}

t_room	*ft_create_room(t_lem *lem, char *data)
{
	t_room	*node;
	char	**splitted;

	node = (t_room *)malloc(sizeof(t_room));
	if (node == NULL)
		ft_error();
	if (ft_count_char(data, ' ') != 2)
		ft_error();
	splitted = ft_strsplit(data, ' ');
	if (splitted[0][0] && splitted[0][0] != 'L'
		&& splitted[0][0] != '#' && ft_count_char(splitted[0], '-') == 0)
		node->name = ft_strdup(splitted[0]);
	else
		ft_error();
	if (ft_check_number(splitted[1]))
		node->x = ft_atoi_unsigned(splitted[1]);
	else
		ft_error();
	if (ft_check_number(splitted[2]))
		node->y = ft_atoi_unsigned(splitted[2]);
	else
		ft_error();
	ft_free_splitted(splitted);
	ft_set_rooms_parameters(lem, node);
	return (node);
}
