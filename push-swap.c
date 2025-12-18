/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzahredd <nzahredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:23:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/18 16:54:15 by nzahredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printff/ft_printf.h"
#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_duplicate(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		printf("true");
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	count_mblocks(char **argv, int **index)
{
	int	i;
	int	count;
	int	j;
	int	k;

	i = 0;
	count = 0;
	k = 0;
	while (argv[i])
	{
		j = 0;
		while (!ft_isdigitt(argv[i][j]))
			j++;
		if (j != ft_strlenn(argv[i]))
			count++;
		i++;
	}
	*index = malloc(count * sizeof(int));
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (!ft_isdigitt(argv[i][j]))
			j++;
		if (j != ft_strlenn(argv[i]))
			(*index)[k++] = i;
		i++;
	}
	return (count);
}

char *ft_strcpy(char *src)
{
	int i;
	char *dst;

	i = 0;
	dst = malloc(ft_strlenn(src) + 1);
	while(src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	check_numbers_validation(char *str)
{
	int		i;
	char	*int_max;
	char	*int_min;

	i = 0;
	int_max = ft_strcpy("2147483647");
	int_min = ft_strcpy("-2147483648");
	if (!check_duplicate(str))
	{
		return (0);
		printf("true");
	}
	if (ft_strcmp(int_max, str) < 0)
		return (0);
	if (ft_strcmp(int_min, str) > 0)
		return (0);
	while (str[i++])
	{
		if (ft_isdigitt(str[i]))
		{
			if (str[i] == '-' || str[i] == '+')
			{
				i++;
				if (!ft_isdigitt(str[i]))
					return (0);
			}
			return (0);
		}
	}
	return (1);
}

int	check_numstr_repetition(char **argv)
{
	int	i;
	int	*index;
	int	k;

	i = 0;
	k = 0;
	if (count_mblocks(argv, &index) == 1)
	{
		if (!ft_isdigitt(argv[index[0]][0])
			|| !ft_isdigitt(argv[index[0]][ft_strlenn(argv[index[0]]) - 1]) || !check_numbers_validation(argv[index[0]]))
			return (0);
		while (argv[index[0]][i])
		{
			if (!ft_isdigitt(argv[index[0]][i]) && argv[index[0]][i] != ' ')
				return (0);
			i++;
		}
	}
	else
	{
		while (k < count_mblocks(argv, &index))
		{
			if (!ft_isdigitt(argv[index[k]][0])
			|| !ft_isdigitt(argv[index[k]][ft_strlenn(argv[index[k]]) - 1]))
				return (0);
			while (argv[index[k]][i])
			{
				if (!ft_isdigitt(argv[index[k]][i]) && argv[index[k]][i] != ' ')
					return (0);
				i++;
			}
			k++;
		}
	}
	return (1);
}

int	ft_check_input_validity(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{

		if (ft_strcmp(argv[i], "--adaptive") && ft_strcmp(argv[i], "--simple")
			&& ft_strcmp(argv[i], "--medium")
			&& ft_strcmp(argv[i], "--complex")
			&& ft_strcmp(argv[i], "--bench")
			&& !check_numstr_repetition(&argv[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	// char	*str;

	i = 1;
	j = 0;
	if (argc == 1)
		return (0);
	printf("true\n");
	if (!ft_check_input_validity(argv))
	{
		ft_printf("error");
		return (0);
	}
	printf("true");
	// str = ft_extract_str_numbers(argc, argv);
	// j = search_strategy_existance(argv);
	// if (j == 0 || ft_strcmp(str,"adaptive") == 0)
	// 	ft_adaptive_process(str);
	// else
	// 	ft_Other_process(str);
	// if(search_bench_existance(argv))
	// 	ft_bench_process();
	return (0);
}
