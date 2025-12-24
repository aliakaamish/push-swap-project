/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaputils5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 11:59:03 by aakaamis          #+#    #+#             */
/*   Updated: 2025/12/24 13:16:31 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printff/ft_printf.h"
#include "push_swap.h"

int	count_mblockshelper(char **argv, int i)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (argv[i] && argv[i][j])
	{
		if (ft_isdigitt(argv[i][j]))
		{
			count++;
			i++;
			j = 0;
		}
		else
		{
			j++;
			if (!argv[i][j])
			{
				j = 0;
				i++;
			}
		}
	}
	return (count);
}

int	count_mblocks(char **argv, int **index)
{
	int	i;
	int	count;
	int	j;
	int	k;

	i = 1;
	count = 0;
	k = 0;
	j = 0;
	count = count_mblockshelper(argv, i);
	*index = malloc(count * sizeof(int));
	if (!*index)
		return (0);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (!ft_isdigitt(argv[i][j]) && argv[i][j])
			j++;
		if (argv[i][j] != '\0')
			(*index)[k++] = i;
		i++;
	}
	return (count);
}

int	check_strategies(char *argv)
{
	int	i;
	int	count_digits;

	i = 0;
	count_digits = 0;
	if (ft_strcmp(argv, "--adaptive") && ft_strcmp(argv, "--simple")
		&& ft_strcmp(argv, "--medium")
		&& ft_strcmp(argv, "--complex")
		&& ft_strcmp(argv, "--bench"))
	{
		while (argv[i])
		{
			if (ft_isdigit(argv[i]))
				count_digits++;
			i++;
		}
		if (count_digits == 0)
			return (0);
	}
	return (1);
}

int	ft_check_input_validity(char **argv, char		**ptr)
{
	int			i;

	i = 1;
	while (argv[i])
	{
		if (!check_strategies(argv[i]))
		{
			return (0);
		}
		if (!check_numstr_repetition(argv, &ptr))
			return (0);
		i++;
	}
	return (1);
}
