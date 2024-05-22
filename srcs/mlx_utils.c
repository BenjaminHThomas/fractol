/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:03:21 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/22 09:51:49 by bthomas          ###   ########.fr       */
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

void	custom_pixel_put(t_mlx_data *mlx, int x, int y, int colour)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->linelen + x * (mlx->bpp / 8));
	*(unsigned int *)dst = colour;
}

float	ft_atof(char *s)
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
		ret += ((double)s[j] - '0') / pow(10, (j - i));
	return (ret * sign);
}
