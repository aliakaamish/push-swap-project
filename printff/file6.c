/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:22:24 by aakaamis          #+#    #+#             */
/*   Updated: 2025/12/18 09:33:25 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_float_print(va_list args)
{
	double				x;
	int					count;

	x = va_arg(args, double);
	ft_putnbr_fd(x, 1);
	count = length_of_int(x);
	return (count);
}
