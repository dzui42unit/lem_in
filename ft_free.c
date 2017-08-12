/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:18:32 by dzui              #+#    #+#             */
/*   Updated: 2017/08/11 14:18:33 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_data(t_lem *lem)
{
	if (lem->ants == 0)
	{
		ft_free_rooms(lem->head);
		ft_free_path(lem->path);
		ft_free_matrix(lem);
		free(lem->lems);
		exit(0);
	}
}

void	ft_free_matrix(t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->size)
	{
		free(lem->adj_matrix[i]);
		i++;
	}
	free(lem->adj_matrix);
}

void	ft_free_rooms(t_room *head)
{
	t_room *start;
	t_room *temp;

	start = head;
	while (start)
	{
		temp = start;
		free(start->name);
		start = start->next;
		free(temp);
	}
}

void	ft_free_path(t_path *path)
{
	t_path *start;
	t_path *temp;

	start = path;
	while (start)
	{
		temp = start;
		free(start->path);
		start = start->next;
		free(temp);
	}
}

void	ft_free_splitted(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
