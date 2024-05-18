/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:09:54 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/18 18:20:31 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	fill_image(t_mlx_data *mlx)
{
	double		x;
	double		y;
	t_complex	c;
	int			n;

	x = 0;
	while (x <= WINWIDTH)
	{
		y = 0;
		while (y <= WINHEIGHT)
		{
			c.x = MINX + x * SCALE_X;
			c.i = MAXI - y * SCALE_Y;
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
