/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:36:17 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/20 21:15:41 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define MAX_ITER 30
# define WINWIDTH 1080
# define WINHEIGHT 720
# define BLACKHEX 0x00000000
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_XBUTT 17
# define MOUSE_WHL_DWN 5
# define MOUSE_WHL_UP 4
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct s_complex
{
	long double	x;
	long double	i;
}	t_complex;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			linelen;
	int			endian;
	long double	MINX;
	long double	MAXX;
	long double	MINI;
	long double	MAXI;
	long double	SCALE_X;
	long double	SCALE_Y;
	int			iters;
	char		set;
	t_complex	z;
}	t_mlx_data;

void	custom_pixel_put(t_mlx_data *mlx, int x, int y, int colour);
float	calc_set(t_complex c, t_mlx_data *mlx);
int		mandelbrot_quick(t_complex c);
int		get_colour(float n, t_mlx_data *mlx);
void	fill_image(t_mlx_data *mlx);
int		buttonpress(int button, t_mlx_data *mlx);
int		clean_close(t_mlx_data *mlx);
int		mouse_scroll(int button, int x, int y, t_mlx_data *mlx);
void	update_scale(t_mlx_data *mlx, int button, int x, int y);
void	refresh_image(t_mlx_data *mlx);
void	shift_img(t_mlx_data *mlx, int button);
void	sharpen(t_mlx_data *mlx, int button);
void	attach_hooks(t_mlx_data *mlx);
int		exit_help(void);

#endif
