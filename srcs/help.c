/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:41:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/20 19:51:33 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	print_instructions(void)
{
	char	*s1;
	char	*s2;

	s1 = "Here are the parameters:\n\tm: mandelbrot set\n\tj: Julia set\n";
	write(1, s1, ft_strlen(s1));
	s2 = "Additionally you can include the starting parameters for the"
			" julia set if you so desire.\n";
	write(1, s2, ft_strlen(s2));
}

int	exit_help(void)
{
	write(2, "Error: Inavlid input\n\n", 22);
	print_instructions();
	return (1);
}
