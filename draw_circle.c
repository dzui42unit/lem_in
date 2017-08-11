/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:28:18 by dzui              #+#    #+#             */
/*   Updated: 2017/08/10 21:28:20 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_pixel_img(t_lem *lem, int x, int y, int color)
{
	char	*px;
	int		p;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		px = mlx_get_data_addr(lem->image, &p, &p, &p);
		p = WIDTH * y * 4 + x * 4;
		px[p + 0] = (char)get_red(color);
		px[p + 1] = (char)get_green(color);
		px[p + 2] = (char)get_blue(color);
	}
}

void	draw_line(t_lem *lem)
{
	lem->dx = abs(lem->x_2 - lem->x_1);
	lem->dy = abs(lem->y_2 - lem->y_1);
	lem->sign_x = lem->x_1 < lem->x_2 ? 1 : -1;
	lem->sign_y = lem->y_1 < lem->y_2 ? 1 : -1;
	lem->error_1 = lem->dx - lem->dy;
	while (lem->x_1 != lem->x_2 || lem->y_1 != lem->y_2)
	{
		put_pixel_img(lem, lem->x_1, lem->y_1, 0x009EE2B2);
		lem->error_2 = lem->error_1 * 2;
		if (lem->error_1 > -(lem->dy))
		{
			lem->error_1 -= lem->dy;
			lem->x_1 += lem->sign_x;
		}
		if (lem->error_2 < lem->dx)
		{
			lem->error_1 += lem->dx;
			lem->y_1 += lem->sign_y;
		}
	}
}

void	ft_circle_simple(t_lem *lem, int x_center, int y_center)
{
	int x;
	int y;

	x = -(lem->radius);
	while (x <= lem->radius)
	{
		y = (int)(sqrt(lem->radius_2 - x * x) + 0.5);
		lem->x_1 = x_center + x;
		lem->y_1 = y_center + y;
		lem->x_2 = x_center + x;
		lem->y_2 = y_center - y;
		draw_line(lem);
		x++;
	}
}

void	img_clear(t_lem *lem)
{
	char	*px;
	int		p;

	px = mlx_get_data_addr(lem->image, &p, &p, &p);
	ft_bzero(px, 4 * WIDTH * HEIGHT);
}

int		get_red(int color)
{
	return ((((color >> 16) & 0xFF)));
}

int		get_green(int color)
{
	return ((((color >> 8) & 0xFF)));
}

int		get_blue(int color)
{
	return (((color) & 0xFF));
}

int		my_key_func(int key_code, t_lem *lem)
{
	if (key_code == 53)
	{
		ft_free_rooms(lem->head);
		ft_free_path(lem->path);
		ft_free_matrix(lem);
		exit(0);
	}
	return (0);
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

void	ft_draw_nodes(t_lem *lem, t_room *head)
{
	t_room	*start;
	int		x;
	int		y;

	start = head;
	while (start)
	{
		x = (int)start->x;
		y = (int)start->y;
		ft_circle_simple(lem, x, y);
		start = start->next;
	}
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
		mlx_string_put(lem->mlx, lem->win, x, y, 0x00E23838, "L");
		x = (int)(room->x) - 7;
		y = (int)(room->y - 7);
		mlx_string_put(lem->mlx, lem->win, x, y, 0x00E23838, number);
		free(number);
	}
}

void	ft_free_data(t_lem *lem)
{
	if (lem->ants == 0)
	{
		ft_free_rooms(lem->head);
		ft_free_path(lem->path);
		ft_free_matrix(lem);
		exit(0);
	}
}

int		ft_visual(t_lem *lem)
{
	t_room	*start;
	char	*number;

	if (lem->flag)
		sleep(4);
	ft_move_lem_visual(lem, lem->path, lem->head);
	img_clear(lem);
	ft_draw_nodes(lem, lem->head);
	ft_draw_connections(lem);
	start = lem->head;
	mlx_put_image_to_window(lem->mlx, lem->win, lem->image, 0, 0);
	while (start)
	{
		mlx_string_put(lem->mlx, lem->win, (int)start->x,
			(int)(start->y - lem->radius * 2 - 10), 0x00A6DEED, start->name);
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
