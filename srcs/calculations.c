/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:01:18 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/19 20:24:39 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

/*
	* f(z) = z^2 + c
	*
	*  f(z) = new position.
	*  z^2 = current postion.
	*  c = starting position.
	*
	*  both z & c are complex numbers with real and imaginary components;
	*  z^2 = (x + yi)(x + yi)
	*  z^2 = x^2 + xyi + xyi - y^2
	*  z^2 = x^2 - y^2 + 2xyi
	
	*/

int	mandelbrot(t_complex c)
{
	t_complex		z;
	int				n;
	long double		temp_x;

	z.x = 0;
	z.i = 0;
	n = 0;
	while (n < MAX_ITER)
	{
		temp_x = (z.x * z.x) - (z.i * z.i) + c.x;
		z.i = 2 * z.x * z.i + c.i;
		z.x = temp_x;
		if ((z.x * z.x + z.i * z.i) > 4)
			break ;
		n++;
	}
	return (n);
}

/*
You can play around with the functions to produce different 
colour schemes

	* The r value is the function:
	*   9 * (1 - t) * t^3
	*   r is a bell curve. Slowly coming to a peak at ~0.77 before
	*   plummeting to 0
	*
	* The g value is a quadratic curve
	*   15 * (1 - t)^2 * t^2
	*   g is also a bell curve but not skewed to the right like r.
	*
	* The b value is a concave curve.
	*   tapering off faster than r.
	*   1 - (1 - t)^2
	*/
int	get_colour(double n)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = n / MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)((1 - (1 - t) * (1 - t)) * 255);
	return ((r << 16) | (g << 8) | b);
}
