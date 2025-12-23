/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaputils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 12:48:42 by aakaamis          #+#    #+#             */
/*   Updated: 2025/12/23 21:04:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_minus_signs(&s1, &s2);
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
			return (s1[i] - s2[j]);
		else if (s1[i] != s2[j])
		{
			if (s1[i] == '+' && ft_isdigitt(s2[j]))
				i++;
			else if (s2[j] == '+' && ft_isdigitt(s1[i]))
				j++;
			else
				return (s1[i] - s2[j]);
		}
		else
			return (s1[i] - s2[j]);
	}
	return (1);
}

int	check_duplicate(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (!ft_strcmp(str[i], str[j]))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

float	ft_compute_disorder(int *a, int len)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			total_pairs += 1;
			if (a[i] > a[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / total_pairs);
}

static int	check_valid_pointer(char *nptr, int *i, int *number2)
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

int	ft_atoi(char *nptr)
{
	int		i;
	int		number1;
	int		number2;

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
		return (0);
}
