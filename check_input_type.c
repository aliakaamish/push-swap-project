/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_strategies.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:57:37 by marvin            #+#    #+#             */
/*   Updated: 2025/12/19 20:57:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "printff/ft_printf.h"

int	ft_strchr(char *s, int c)
{
	int	count_spaces;

	count_spaces = 0;
	while (*s)
	{
		if (*s == (char)c)
			count_spaces++;
		s++;
	}
		return (count_spaces);
}

static int	ft_is_strategy_flag(char *arg)
{
	return (!ft_strcmp(arg, "--simple")
		|| !ft_strcmp(arg, "--complex")
		|| !ft_strcmp(arg, "--medium")
		|| !ft_strcmp(arg, "--adaptive"));
}

static int	ft_is_number_arg(char *arg)
{
	return (ft_isdigit(arg[0]) || arg[0] == '-' || arg[0] == '+');
}

static void	ft_count_args(char **argv, int *counts)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_is_strategy_flag(argv[i]))
			counts[0]++;
		else if (!ft_strcmp(argv[i], "--bench"))
			counts[1]++;
		else if (ft_is_number_arg(argv[i]))
		{
			counts[2]++;
			if (ft_strchr(argv[i], ' '))
				counts[3]++;
		}
		i++;
	}
}

int	ft_input_type(char **argv)
{
	int	counts[4];

	counts[0] = 0; // count_strategy
	counts[1] = 0; // count_bench
	counts[2] = 0; // count_numbers
	counts[3] = 0; // has_space

	ft_count_args(argv, counts);

	if (counts[0] > 1 || counts[1] > 1)
		return (0);
	if (counts[3] >= 1 && counts[2] > 1)
		return (0);
	return (1);
}
