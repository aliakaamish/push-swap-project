/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 21:56:50 by aakaamis          #+#    #+#             */
/*   Updated: 2025/11/22 20:47:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_string(const char *sentence, int *i)
{
	int	count;

	count = 0;
	while (sentence[*i] != '%' && sentence[*i])
	{
		write(1, &sentence[(*i)++], 1);
		count++;
	}
	return (count);
}

int	ft_int_print(va_list args)
{
	int		x;
	char	*ptr;
	int		count;

	x = va_arg(args, int);
	ptr = ft_itoa(x);
	count = write(1, ptr, ft_strlen(ptr));
	free(ptr);
	return (count);
}

int	ft_string_print(va_list args)
{
	char	*ptr;

	ptr = va_arg(args, char *);
	if (ptr == 0)
		return (write(1, "(null)", 6));
	return (write(1, ptr, ft_strlen(ptr)));
}

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	convert_to_hexadecimal(unsigned long n, int x)
{
	char	*hex;
	int		i;

	i = 0;
	if (x == 1)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
		i += (convert_to_hexadecimal(n / 16, x));
	i += ft_printchar(hex[n % 16]);
	return (i);
}
