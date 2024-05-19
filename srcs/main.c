/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:36:02 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/19 13:44:08 by bthomas          ###   ########.fr       */
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
}

static int	print_mouse(int x, int y, t_mlx_data *mlx)
{
	x = 0;
	y = 0;
	mlx_mouse_get_pos(mlx->mlx, mlx->win, &x, &y);
	printf("x: %d y: %d\n", x, y);
	return (0);
}

int	main(void)
{
	t_mlx_data	mlx;

	initialise(&mlx);
	fill_image(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_key_hook(mlx.win, keypress, &mlx);
	mlx_hook(mlx.win, 6, (1L << 6), print_mouse, &mlx);
	mlx_hook(mlx.win, KEY_XBUTT, 0, clean_close, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
