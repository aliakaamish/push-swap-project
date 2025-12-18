/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:40:37 by aakaamis          #+#    #+#             */
/*   Updated: 2025/11/28 07:45:03 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	length_of_int(unsigned int x)
{
	int	count;

	if (x == 0)
		count = 1;
	else
		count = 0;
	while (x != 0)
	{
		x /= 10;
		count++;
	}
	return (count);
}
