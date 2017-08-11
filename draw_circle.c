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
