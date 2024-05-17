/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:36:17 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/17 10:43:54 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

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
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int colour);

#endif
