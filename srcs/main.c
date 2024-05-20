/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:36:02 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/20 10:54:32 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdio.h>

static void	initialise(t_mlx_data *mlx)
{
	ft_memset(mlx, 0, sizeof(mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, WINWIDTH, WINHEIGHT, "Hello world");
	mlx->img = mlx_new_image(mlx->mlx, WINWIDTH, WINHEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->linelen,
			&mlx->endian);
	mlx->MINX = -2.5;
	mlx->MAXX = 1.5;
	mlx->MINI = -1.5;
	mlx->MAXI = 1.5;
	mlx->SCALE_X = (mlx->MAXX - mlx->MINX) / (WINWIDTH - 1);
	mlx->SCALE_Y = (mlx->MAXI - mlx->MINI) / (WINHEIGHT - 1);
	mlx->iters = MAX_ITER;
}

int	main(void)
{
	t_mlx_data	mlx;

	initialise(&mlx);
	fill_image(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	attach_hooks(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
