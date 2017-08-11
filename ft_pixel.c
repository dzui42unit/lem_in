/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 14:47:02 by dzui              #+#    #+#             */
/*   Updated: 2017/08/11 14:47:05 by dzui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
