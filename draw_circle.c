#include "lem_in.h"

void	put_pixel_img(t_lem *lem, int x, int y, int color)
{
	char	*px;
	int		p;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		px = mlx_get_data_addr(lem->image, &p, &p, &p);
		p = WIDTH * y * 4 + x * 4;
		px[p + 0] = get_red(color);
		px[p + 1] = get_green(color);
		px[p + 2] = get_blue(color);
	}
}

void	draw_line(t_lem *lem, int x1, int y1, int x2, int y2)
{
	float dx = fabs(x2 - x1);
	float dy = fabs(y2 - y1);
	int sign_x = x1 < x2 ? 1 : -1;
	int sign_y = y1 < y2 ? 1 : -1;
	float error1 = dx - dy;
	while (x1 != x2 || y1 != y2)
	{
		put_pixel_img(lem, x1, y1, 0x00FFFFFF);
		float error2 = error1 * 2;
		if (error2 > -(dy))
		{
			error1 -= dy;
			x1 += sign_x;
		}
		if (error2 < dx)
		{
			error1 += dx;
			y1 += sign_y;
		}
	}
}


void 	circleSimple(t_lem *lem, int xCenter, int yCenter, int radius, int color)
{
	int x, y, r2;    

	r2 = radius * radius;
	for (x = -radius; x <= radius; x++)
	{
		y = (int) (sqrt(r2 - x*x) + 0.5);
		draw_line(lem, xCenter + x, yCenter + y, xCenter + x, yCenter - y);
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
	return ((int)(((color >> 16) & 0xFF)));
}

int		get_green(int color)
{
	return ((int)(((color >> 8) & 0xFF)));
}

int		get_blue(int color)
{
	return ((int)((color) & 0xFF));
}

int		my_key_func(int key_code, t_lem *lem)
{
	if (key_code == 53)
	{
		exit(0);
	}
	return (0);
}

int		ft_draw_graph(t_lem *lem)
{
	lem->mlx = mlx_init();
	lem->win = mlx_new_window(lem->mlx, WIDTH, HEIGHT, "lem_in");
	lem->image = mlx_new_image(lem->mlx, WIDTH, HEIGHT);
	mlx_hook(lem->win, 2, 3, my_key_func, lem);
	mlx_loop_hook(lem->mlx, &ft_visual, lem);
	mlx_loop(lem->mlx);
	return (0);
}
