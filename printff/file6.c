/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 09:22:24 by aakaamis          #+#    #+#             */
/*   Updated: 2025/12/18 10:35:00 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlenn(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_concatenate(char *dest, char *src)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (src == NULL)
		return (NULL);
	ptr = malloc(ft_strlenn(dest) + ft_strlenn(src) + 1);
	while (dest[i])
	{
		ptr[i] = dest[i];
		i++;
	}
	while (src[j])
		ptr[i++] = src[j++];
	ptr[i] = '\0';
	return (ptr);
}

int	ft_float_print(va_list args)
{
	double				number;
	int					a;
	char				*ptr;
	int					count;
	int					k;

	number = va_arg(args, double);
	a = number;
	ptr = ft_itoa(a);
	ptr = ft_concatenate(ptr, ".");
	number = number - a;
	k = 0;
	a = 0;
	while (number != 0 && k < 2)
	{
		number = number / 0.1;
		a = a * 10 + (int)number;
		number = number - (int)number;
		k++;
	}
	ptr = ft_concatenate(ptr, ft_itoa(a));
	write(1, ptr, ft_strlen(ptr));
	count = ft_strlen(ptr);
	return (count);
}
