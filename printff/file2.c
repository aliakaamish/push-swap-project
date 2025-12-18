/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:38:00 by aakaamis          #+#    #+#             */
/*   Updated: 2025/11/21 15:33:39 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	length_of_integer(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static char	*ft_helper(int *index, char *ptr, long *number)
{
	if (*number == 0)
		ptr[*index] = '0';
	while (*number != 0)
	{
		ptr[*index] = *number % 10 + '0';
		(*number) /= 10;
		(*index)--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	number;
	int		index;

	if (n < 0)
	{
		number = n;
		number = -number;
		ptr = (char *)malloc((length_of_integer(-number) + 2) * sizeof(char));
		if (ptr == NULL)
			return (0);
		ptr[0] = '-';
		index = length_of_integer(number) + 1;
	}
	else
	{
		number = n;
		ptr = (char *)malloc((length_of_integer(number) + 1) * sizeof(char));
		if (ptr == 0)
			return (0);
		index = length_of_integer(number);
	}
	ptr[index] = '\0';
	index--;
	return (ft_helper(&index, ptr, &number));
}
