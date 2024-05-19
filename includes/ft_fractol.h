/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:36:17 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/18 19:54:54 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# define MAX_ITER 40
# define WINWIDTH 1080
# define WINHEIGHT 720
# define MINX -2.5
# define MAXX 1.5
# define MINI -1.5
# define MAXI 1.5
# define SCALE_X (MAXX - MINX) / (WINWIDTH - 1)
# define SCALE_Y (MAXI - MINI) / (WINHEIGHT - 1)
# define BLACKHEX 0x00000000
# define KEY_ESC 65307
# define KEY_XBUTT 17
# define MOUSE_WHL_DWN 5
# define MOUSE_WHL_UP 4
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"

/* Struct used to store info about our window.
 *
 * bpp = bits per pixel.
 *
 * endian:
 * 		The byte order used to represent data in memory.
 *		Endian-ness determines how multi-byte data is stored and interpreted.
 *		There are 2 types:
 *			Big-endian: The most significant byte (the "big end") of a word
 *				is stored at the smallest memory address & the least signif 
 *				at the largest.
 *			little-endian: the opposite of big-endian.
 *
 *		If you're a normal person, running the program on a normal 
 *		x86 processor, then you'll be using little-endian.
 *
 *	The reason it's important for X11 is that it has to:
 *		Byte swap the data if the server and client are using different 
 *		systems.
 *		When you initialise X11 you send a byte to the server, indicating
 *			the endian-ness.
 */
typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
}	t_mlx_data;

typedef struct s_complex
{
	double	x;
	double	i;
}	t_complex;

void	custom_pixel_put(t_mlx_data *data, int x, int y, int colour);
int		mandelbrot(t_complex c);
int		get_colour(double n);
void	fill_image(t_mlx_data *mlx);
int		keypress(int keycode, t_mlx_data *mlx);
int		clean_close(t_mlx_data *mlx);

#endif
