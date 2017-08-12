/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjecency_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:18:28 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 21:18:29 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_allocate_matrix(t_lem *lem)
{
	int	i;
	int	j;

	i = 0;
	lem->visited = (int *)malloc(sizeof(int) * lem->size);
	lem->adj_matrix = (int **)malloc(sizeof(int *) * lem->size);
	while (i < lem->size)
	{
		lem->adj_matrix[i] = (int *)malloc(sizeof(int) * lem->size);
		lem->visited[i] = -1;
		i++;
	}
	i = 0;
	while (i < lem->size)
	{
		j = 0;
		while (j < lem->size)
		{
			lem->adj_matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_process_first_link(t_lem *lem, t_room *head, char *buff)
{
	char	**splitted;
	int		i;
	int		j;

	splitted = ft_strsplit(buff, '-');
	i = ft_find_list_element(head, splitted[0]);
	j = ft_find_list_element(head, splitted[1]);
	if (i == -1 || j == -1)
		ft_error();
	if (i != j)
	{
		lem->adj_matrix[i][j] = 1;
		lem->adj_matrix[j][i] = 1;
	}
	ft_free_splitted(splitted);
}

void	ft_process_links(t_lem *lem, t_room *head, char *buff)
{
	char	**splitted;
	int		i;
	int		j;

	if (ft_count_char(buff, '-') != 1)
		ft_error();
	splitted = ft_strsplit(buff, '-');
	i = ft_find_list_element(head, splitted[0]);
	j = ft_find_list_element(head, splitted[1]);
	if (i == -1 || j == -1)
		ft_error();
	if (i != j)
	{
		lem->adj_matrix[i][j] = 1;
		lem->adj_matrix[j][i] = 1;
	}
	ft_free_splitted(splitted);
}

void	ft_make_matrix(t_room *head, t_lem *lem, char *buff)
{
	if (ft_count_char(buff, '-') != 1)
		ft_error();
	ft_allocate_matrix(lem);
	ft_process_first_link(lem, head, buff);
	ft_join(lem, buff);
	free(buff);
	while (get_next_line(0, &buff))
	{
		if (ft_strequ(buff, "##start") || ft_strequ(buff, "##end")
			|| ft_strequ(buff, "") || ft_strequ(buff, "##path"))
			ft_error();
		if (!ft_is_comment(buff))
			ft_process_links(lem, head, buff);
		ft_join(lem, buff);
		free(buff);
	}
	free(buff);
}
