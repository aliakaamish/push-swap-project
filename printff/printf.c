/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:22:04 by aakaamis          #+#    #+#             */
/*   Updated: 2025/12/18 10:26:28 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	ft_address_print_p(va_list args, int x)
{
	unsigned long	n;

	n = va_arg(args, unsigned long);
	if (n == 0)
		return (write(1, "(nil)", 5));
	if (x == 1)
		return (write(1, "0x", 2) + convert_to_hexadecimal(n, 1));
	else
		return (write(1, "0x", 2) + convert_to_hexadecimal(n, -1));
}

int	ft_address_print_x(va_list args, int x)
{
	unsigned long	n;

	n = va_arg(args, unsigned int);
	if (x == 1)
		return (convert_to_hexadecimal(n, 1));
	else
		return (convert_to_hexadecimal(n, -1));
}

int	ft_unsigned_int_print(va_list args)
{
	unsigned int		x;
	int					count;

	x = va_arg(args, unsigned int);
	ft_putnbr_fd(x, 1);
	count = length_of_int(x);
	return (count);
}

int	ft_string_iterate_check(const char *sentence,
	va_list args, int index)
{
	if (sentence[index] == 'd' || sentence[index] == 'i')
		return (ft_int_print(args));
	if (sentence[index] == 's')
		return (ft_string_print(args));
	if (sentence[index] == 'p')
		return (ft_address_print_p((void *)args, 1));
	if (sentence[index] == 'x')
		return (ft_address_print_x((void *)args, 1));
	if (sentence[index] == 'c')
		return (ft_printchar((char)va_arg(args, int)));
	if (sentence[index] == 'f')
		return (ft_float_print(args));
	if (sentence[index] == 'u')
		return (ft_unsigned_int_print(args));
	if (sentence[index] == 'X')
		return (ft_address_print_x(args, -1));
	if (sentence[index] == '%')
		return (ft_printchar('%'));
	return (0);
}

int	ft_printf(const char	*sentence, ...)
{
	int		i;
	va_list	args;
	int		count;

	i = 0;
	count = 0;
	va_start(args, sentence);
	while (sentence[i])
	{
		if (sentence[i] == '%')
		{
			i++;
			count += ft_string_iterate_check(sentence, args, i);
			i++;
		}
		else
		{
			count += write_string(sentence, &i);
		}
	}
	va_end(args);
	return (count);
}
