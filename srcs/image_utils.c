/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:09:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/19 21:51:54 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdio.h>

void	refresh_image(t_mlx_data *mlx)
{
	fill_image(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	update_scale(t_mlx_data *mlx, int button, int x, int y)
{
	long double	x_offset;
	long double	y_offset;
	long double	zoom_fact;

	if (button == MOUSE_WHL_DWN)
		zoom_fact = 0.9;
	else
		zoom_fact = 1.05;
	x_offset = mlx->MINX + x * mlx->SCALE_X;
	y_offset = mlx->MINI + y * mlx->SCALE_Y;
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
	int				n;

	x = 0;
	while (x <= WINWIDTH)
	{
		y = 0;
		while (y <= WINHEIGHT)
		{
			c.x = mlx->MINX + x * mlx->SCALE_X;
			c.i = mlx->MAXI - y * mlx->SCALE_Y;
			n = mandelbrot(c);
			if (n < MAX_ITER)
				custom_pixel_put(mlx, x, y, get_colour(n));
			else
				custom_pixel_put(mlx, x, y, BLACKHEX);
			y++;
		}
		x++;
	}
}
