/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:26:16 by aakaamis          #+#    #+#             */
/*   Updated: 2025/11/21 20:35:57 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_single_digit(long number, int fd)
{
	char	c;

	if (number == 0)
		write(fd, "0", 1);
	else
	{
		c = number % 10 + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n / 10 == 0)
		return (handle_single_digit(n, fd));
	ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
