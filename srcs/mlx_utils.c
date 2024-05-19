/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:03:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/19 21:52:23 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdio.h>

int	clean_close(t_mlx_data *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_loop_end(mlx->mlx);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(1);
	return (0);
}

int	keypress(int keycode, t_mlx_data *mlx)
{
	if (keycode == KEY_ESC)
		clean_close(mlx);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_mlx_data *mlx)
{
	if (button == MOUSE_WHL_DWN || button == MOUSE_WHL_UP)
	{
		mlx_mouse_get_pos(mlx->mlx, mlx->win, &x, &y);
		update_scale(mlx, button, x, y);
		refresh_image(mlx);
	}
	return (0);
}

void	custom_pixel_put(t_mlx_data *mlx, int x, int y, int colour)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->linelen + x * (mlx->bpp / 8));
	*(unsigned int *)dst = colour;
}
