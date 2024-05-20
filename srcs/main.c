/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:36:02 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/20 20:04:39 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"
#include <stdio.h>

static float	ft_atof(char *s)
{
	int		i;
	int		j;
	int		sign;
	double	ret;

	ret = 0.0;
	i = -1;
	sign = 1;
	while (s[++i] && !ft_isdigit(s[i]))
		if (s[i] == '-')
			sign *= -1;
	while (ft_isdigit(s[i]))
	{
		ret *= 10;
		ret += s[i] - '0';
		i++;
	}
	if (s[i] != '.')
		return (ret * sign);
	j = i;
	while (s[++j] && ft_isdigit(s[j]))
		ret += ((double)s[j]  - '0') / pow(10, (j - i));
	return (ret * sign);
}

static void	initialise(t_mlx_data *mlx, char **av, int ac)
{
	ft_memset(mlx, 0, sizeof(mlx));
	mlx->set = *av[1];
	if (mlx->set == 'm' || ac < 4)
	{
		mlx->z.x = 0;
		mlx->z.i = 0;
	}
	else
	{
		mlx->z.x = ft_atof(av[2]);
		mlx->z.i = ft_atof(av[3]);
	}
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

int	main(int ac, char **av)
{
	t_mlx_data	mlx;

	if (ac < 2)
		return (exit_help());
	if (*av[1] != 'm' && *av[1] != 'j')
		return (exit_help());
	printf("initialising...\n");
	initialise(&mlx, av, ac);
	printf("filling image...\n");
	fill_image(&mlx);
	printf("putting image to window...\n");
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	attach_hooks(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
