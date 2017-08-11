/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:36:27 by dzui              #+#    #+#             */
/*   Updated: 2017/08/11 14:36:29 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_draw_nodes(t_lem *lem, t_room *head)
{
	t_room	*start;
	int		x;
	int		y;

	img_clear(lem);
	start = head;
	while (start)
	{
		x = (int)start->x;
		y = (int)start->y;
		ft_circle_simple(lem, x, y);
		start = start->next;
	}
	ft_draw_connections(lem);
	mlx_put_image_to_window(lem->mlx, lem->win, lem->image, 0, 0);
}

void	ft_draw_connections(t_lem *lem)
{
	int	i;
	int	j;

	i = 0;
	while (i < lem->size)
	{
		j = 0;
		while (j < lem->size)
		{
			if (lem->adj_matrix[i][j] == 1)
			{
				lem->x_1 = (int)ft_get_room(lem->head, i)->x;
				lem->y_1 = (int)ft_get_room(lem->head, i)->y;
				lem->x_2 = (int)ft_get_room(lem->head, j)->x;
				lem->y_2 = (int)ft_get_room(lem->head, j)->y;
				draw_line(lem);
			}
			j++;
		}
		i++;
	}
}

void	ft_print_lems_in_rooms(t_lem *lem, t_room *room)
{
	char	*number;
	int		x;
	int		y;

	if (room->active_lem != 0)
	{
		x = (int)room->x - 18;
		y = (int)(room->y) - 7;
		number = ft_itoa((int)room->active_lem);
		mlx_string_put(lem->mlx, lem->win, x, y, 0x00428BE5, "L");
		x = (int)(room->x) - 7;
		y = (int)(room->y - 7);
		mlx_string_put(lem->mlx, lem->win, x, y, 0x00428BE5, number);
		free(number);
	}
}

int		ft_draw_graph(t_lem *lem)
{
	lem->mlx = mlx_init();
	lem->win = mlx_new_window(lem->mlx, WIDTH, HEIGHT, "lem_in");
	lem->image = mlx_new_image(lem->mlx, WIDTH, HEIGHT);
	mlx_loop_hook(lem->mlx, &ft_visual, lem);
	mlx_hook(lem->win, 2, 3, my_key_func, lem);
	mlx_loop(lem->mlx);
	return (0);
}

int		ft_visual(t_lem *lem)
{
	t_room	*start;
	char	*number;
	int		y;
	int		x;

	if (lem->flag)
		sleep(4);
	ft_move_lem_visual(lem, lem->path, lem->head);
	ft_draw_nodes(lem, lem->head);
	start = lem->head;
	while (start)
	{
		y = (int)(start->y - lem->radius * 2 - 10);
		x = (int)start->x;
		mlx_string_put(lem->mlx, lem->win, x, y, 0x00A6DEED, start->name);
		ft_print_lems_in_rooms(lem, start);
		start = start->next;
	}
	lem->flag = 1;
	number = ft_itoa((int)lem->ants);
	mlx_string_put(lem->mlx, lem->win, 10, 10, 0x00FFFFFF, "ANTS LEFT: ");
	mlx_string_put(lem->mlx, lem->win, 120, 10, 0x00EAAB52, number);
	free(number);
	ft_free_data(lem);
	return (0);
}
