/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:23:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/23 21:07:54 by marvin           ###   ########.fr       */
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

int	ft_check_input_validity(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_strategies(argv[i]))
		{
			return (0);
		}
		if (!check_numstr_repetition(argv))
			return (0);
		i++;
	}
	return (1);
}

/*int	main(int argc, char **argv)
{
	//int		i;
	//int		j;
	// char	*str;

	//i = 1;
	//j = 0;
	if (argc == 1)
		return (0);
	if (!ft_check_input_validity(argv))
	{
		ft_printf("error");
		ft_printf("\n");
		return (0);
	}
	printf("true\n");
	// str = ft_extract_str_numbers(argc, argv);
	// j = search_strategy_existance(argv);
	// if (j == 0 || ft_strcmp(str,"adaptive") == 0)
	// 	ft_adaptive_process(str);
	// else
	// 	ft_Other_process(str);
	// if(search_bench_existance(argv))
	// 	ft_bench_process();
	return (0);
}*/
