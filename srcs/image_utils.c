/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:09:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/22 09:19:34 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdio.h>

void	refresh_image(t_mlx_data *mlx)
{
	fill_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	shift_img(t_mlx_data *mlx, int button)
{
	long double	x_shift;
	long double	y_shift;

	x_shift = 0.0;
	y_shift = 0.0;
	if (button == XK_Left)
		x_shift = -25.0;
	if (button == XK_Right)
		x_shift = 25.0;
	if (button == XK_Up)
		y_shift = 25.0;
	if (button == XK_Down)
		y_shift = -25.0;
	mlx->MINX += x_shift * mlx->SCALE_X;
	mlx->MAXX += x_shift * mlx->SCALE_X;
	mlx->MINI += y_shift * mlx->SCALE_Y;
	mlx->MAXI += y_shift * mlx->SCALE_Y;
	mlx->SCALE_X = (mlx->MAXX - mlx->MINX) / (WINWIDTH - 1);
	mlx->SCALE_Y = (mlx->MAXI - mlx->MINI) / (WINHEIGHT - 1);
	refresh_image(mlx);
}

void	sharpen(t_mlx_data *mlx, int button)
{
	if (button == 45 && mlx->iters > 10)
		mlx->iters -= 5;
	else if (button == 61)
		mlx->iters += 5;
	refresh_image(mlx);
}

void	update_scale(t_mlx_data *mlx, int button, int x, int y)
{
	long double	x_offset;
	long double	y_offset;
	long double	zoom_fact;

	if (button == MOUSE_WHL_DWN)
		zoom_fact = 0.80;
	else
		zoom_fact = 1.30;
	x_offset = mlx->MINX + x * mlx->SCALE_X;
	y_offset = mlx->MAXI - y * mlx->SCALE_Y;
	mlx->MINX = x_offset + (mlx->MINX - x_offset) * zoom_fact;
	mlx->MAXX = x_offset + (mlx->MAXX - x_offset) * zoom_fact;
	mlx->MINI = y_offset + (mlx->MINI - y_offset) * zoom_fact;
	mlx->MAXI = y_offset + (mlx->MAXI - y_offset) * zoom_fact;
	mlx->SCALE_X = (mlx->MAXX - mlx->MINX) / (WINWIDTH - 1);
	mlx->SCALE_Y = (mlx->MAXI - mlx->MINI) / (WINHEIGHT - 1);
}

void	fill_image(t_mlx_data *mlx)
{
	long double		x;
	long double		y;
	t_complex		c;
	float			n;

	x = -1;
	while (++x <= WINWIDTH)
	{
		y = -1;
		while (++y <= WINHEIGHT)
		{
			c.x = mlx->MINX + x * mlx->SCALE_X;
			c.i = mlx->MAXI - y * mlx->SCALE_Y;
			if (mlx->set == 'm' && mandelbrot_quick(c))
				n = mlx->iters;
			else if (mlx->set != 'b')
				n = calc_set(c, mlx);
			else
				n = burning_ship(c, mlx);
			if (n < mlx->iters)
				custom_pixel_put(mlx, x, y, get_colour(n, mlx));
			else
				custom_pixel_put(mlx, x, y, BLACKHEX);
		}
	}
}
