/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numstrrepetition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 21:41:41 by marvin            #+#    #+#             */
/*   Updated: 2025/12/24 13:12:33 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printff/ft_printf.h"
#include "push_swap.h"

// these are all the split version of the check number str repetition
int	numstrisdigithelper(char **ptr, int k, int j)
{
	if (!ft_isdigitt(ptr[k][j])
		&& ptr[k][j] != '+' && ptr[k][j] != '-' )
		return (0);
	if (ptr[k][j] == ' ' && !ft_isdigitt(ptr[k][j + 1])
		&& ptr[k][j + 1] != '+' && ptr[k][j + 1] != '-')
		return (0);
	return (1);
}

int	check_numstr_repetition_helper(char **ptr, int k, int j)
{
	while (ptr[++k])
	{
		j = 0;
		while (ptr[k][j])
		{
			if (!numstrisdigithelper(ptr, k, j))
				return (0);
			if ((ptr[k][j] == '+' || ptr[k][j] == '-'))
			{
				j++;
				while (ptr[k][j] != ' ' && ptr[k][j])
				{
					if (!ft_isdigit(ptr[k][j]))
						return (0);
					j++;
				}
			}
			else
				j++;
		}
	}
	return (1);
}

int	checknumstrhelper2(char **argv, int **index, char **ptr, int *count)
{
	*count = count_mblocks(argv, index);
	if (*count == 1)
		ptr = ft_split(argv[(*index)[0]], ' ');
	else
		ptr = ft_extract_numbers(argv, *index, *count);
	if (!ft_input_type(argv) || !check_duplicate(ptr))
	{
		free(*index);
		free(ptr);
		return (0);
	}
	return (1);
}

int	validate_numbers(char **ptr, int k)
{
	int	j;

	j = 0;
	while (ptr[j])
	{
		if (!check_numbers_validation(ptr[j]))
			return (0);
		j++;
	}
	if (!check_numstr_repetition_helper(ptr, k, j))
		return (0);
	return (1);
}

int	check_numstr_repetition(char **argv, char ***ptr)
{
	int		*index;
	int		count;
	int		k;

	k = -1;
	printf("helper is fine\n");
	if (!checknumstrhelper2(argv, &index, *ptr, &count))
	{
		printf("here cool");
		return (0);
	}
	if (!validate_numbers(ptr, k))
	{
		free(index);
		free(ptr);
		return (0);
	}
	free(index);
	free(ptr);
	return (1);
}
