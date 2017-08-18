/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:52:32 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 20:52:34 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_parts(t_lem *lem, t_path *node, t_room *head)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < lem->size && node->path[i] != -1)
	{
		ft_printf("%s", ft_get_room(head, node->path[i])->name);
		if (j < node->length - 1)
		{
			ft_printf(" -> ");
			j++;
		}
		i++;
	}
}

void	ft_print_path(t_lem *lem, t_room *head, t_path *head_path)
{
	int		counter;
	t_path	*current;

	counter = 0;
	current = head_path;
	ft_printf("\n");
	while (current)
	{
		if (current->active)
		{
			ft_printf("path #%d\n", counter + 1);
			ft_print_parts(lem, current, head);
			ft_printf("\n");
			counter++;
		}
		current = current->next;
	}
}
