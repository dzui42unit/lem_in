/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:17:34 by dzui              #+#    #+#             */
/*   Updated: 2017/08/11 14:17:35 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_sort_path(t_path *head)
{
	t_path	*current;
	t_path	*start;
	t_path	*min;

	if (head)
		start = head;
	else
		return ;
	while (start)
	{
		min = start;
		current = min->next;
		while (current)
		{
			if (min->length > current->length)
				min = current;
			current = current->next;
		}
		if (min != start)
			ft_swap_nodes_path(start, min);
		start = start->next;
	}
}

void	ft_swap_nodes_path(t_path *node_1, t_path *node_2)
{
	t_path	*temp;

	temp = (t_path *)malloc(sizeof(t_path));
	temp->length = node_1->length;
	temp->path = node_1->path;
	node_1->length = node_2->length;
	node_1->path = node_2->path;
	node_2->length = temp->length;
	node_2->path = temp->path;
	temp->path = NULL;
	free(temp);
}

t_path	*ft_create_path(t_lem *lem, int *visited)
{
	t_path	*node;
	int		i;
	int		len;

	node = (t_path *)malloc(sizeof(t_path));
	if (node == NULL)
	{
		ft_printf("ERROR!\n");
		exit(0);
	}
	node->path = (int *)malloc(sizeof(int) * lem->size);
	i = 0;
	len = 0;
	while (i < lem->size)
	{
		node->path[i] = visited[i];
		if (visited[i] != -1)
			len++;
		i++;
	}
	node->active = 1;
	node->length = len;
	node->next = NULL;
	return (node);
}

void	ft_append_path(t_path **head, t_lem *lem, int *visited)
{
	t_path	*conductor;
	t_path	*new_node;

	conductor = *head;
	while (conductor->next)
		conductor = conductor->next;
	new_node = ft_create_path(lem, visited);
	conductor->next = new_node;
}
