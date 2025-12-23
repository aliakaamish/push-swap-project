/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_advanced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:53:21 by marvin            #+#    #+#             */
/*   Updated: 2025/12/19 11:53:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static int	check_valid_pointer(char *nptr, int *i, long long *number2)
{
	if ((nptr[*i] == '+' || nptr[*i] == '-')
		&& (nptr[*i + 1] != '+' && nptr[*i + 1] != '-'
			&& ft_isdigitt(nptr[*i + 1])))
	{
		if (nptr[*i] == '-')
			*number2 *= -1;
		(*i)++;
		return (1);
	}
	else
	{
		return (0);
	}
}
//for ft_atoi

long long	ft_atoi_advanced(char *nptr)
{
	int				i;
	long long		number1;
	long long		number2;

	i = 0;
	number1 = 0;
	number2 = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (check_valid_pointer(nptr, &i, &number2) || ft_isdigitt(nptr[i]))
	{
		while (nptr[i] && (ft_isdigitt(nptr[i])))
			number1 = number1 * 10 + (nptr[i++] - '0');
		if (number2 < 0)
			number1 *= -1;
		return (number1);
	}
	else
	{
		return (0);
	}
}
