/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bthomas <bthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:41:33 by bthomas           #+#    #+#             */
/*   Updated: 2024/05/22 10:13:38 by bthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

static void	print_instructions(void)
{
	char	*s1;
	char	*s2;
	char	*s3;

	s1 = "Here are the parameters:\n\tm: mandelbrot set\n\tj: Julia set\n"
		"\tb: burning ship set\n";
	write(1, s1, ft_strlen(s1));
	s2 = "\nFor the julia set please include the 2 starting parameters.\n"
		"I recommend values between 1.0 & -1.0\n\n";
	write(1, s2, ft_strlen(s2));
	s3 = "You can adjust rgb values with:"
		"\n\tr: q-- w++\n\tg: a-- s++\n\tb: z-- x++\n"
		"\nUse + & - to adjust the precision,\nand arrow keys for direction.";
	write(1, s3, ft_strlen(s3));
}

int	exit_help(void)
{
	write(2, "Error: Inavlid input\n\n", 22);
	print_instructions();
	return (1);
}
