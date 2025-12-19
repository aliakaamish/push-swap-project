/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:23:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/19 13:17:08 by marvin           ###   ########.fr       */
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

int	ft_isdigitt(int c)
{
	if ((c < '0' || c > '9') && c != ' ')
		return (0);
	else
	{
		return (1);
	}
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
	while (argv[i])
	{
		j = 0;
		while (!ft_isdigitt(argv[i][j]))
			j++;
		if (j - 1  != ft_strlenn(argv[i]))
			count++;
		i++;
	}
	*index = malloc(count * sizeof(int));
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (!ft_isdigitt(argv[i][j]))
			j++;
		if (j - 1  != ft_strlenn(argv[i]))
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

	i = 0;
	if(ft_atoi_advanced(str) > INT_MAX || ft_atoi_advanced(str) < INT_MIN)
	{
		return (0);
	}
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (!ft_isdigitt(str[i]))
			{
				printf("here\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	check_numstr_repetition(char **argv)
{
	int	j;
	int	*index;
	char **ptr;
	int	k;

	j = 0;
	k = 0;
	if (count_mblocks(argv, &index) == 1)
	{
		printf("in count==1\n");
		if (!(argv[index[0]][0] - ' ')
			|| !ft_strcmp(&argv[index[0]][ft_strlenn(argv[index[0]]) - 1], " "))
			return (0);
		while (argv[index[0]][j])
		{
			if (!ft_isdigitt(argv[index[0]][j])
				&& argv[index[0]][j] != '+' && argv[index[0]][j] != '-' )
			{
				printf("here\n");
				return (0);
			}
			if(argv[index[0]][j] == ' ' && !ft_isdigit(argv[index[0]][j + 1])
				&& argv[index[0]][j + 1] != '+' && argv[index[0]][j + 1] != '-')
			{
				printf("here\n");
				return (0);
			}
			if((argv[index[0]][j] == '+' || argv[index[0]][j] == '-'))
			
				j++;
				while(argv[index[0]][j] != ' ' && argv[index[0]][j])
				{
					if(!ft_isdigit(argv[index[0]][j]))
					{
						printf("incheck\n");
						return (0);
					}
					j++;
				}
			}
			else
			{
				j++;
			}
		}
		ptr=ft_split(argv[index[0]], ' ');
		j = 0;
		printf("before split\n");
		if(!check_duplicate(ptr))
		{
			printf("duplicate\n");
			return (0);
		}
		while(ptr[j])
		{
			if(!check_numbers_validation(ptr[j]))
			{
				printf("split\n");
				return (0);
			}
			j++;
		}
	}
	else
	{
		printf("in count>1\n");
		while (k < count_mblocks(argv, &index))
		{
			if (!ft_isdigitt(argv[index[k]][0])
			|| !ft_isdigitt(argv[index[k]][ft_strlenn(argv[index[k]]) - 1]))
				return (0);
			while (argv[index[k]][j])
			{
				if (!ft_isdigitt(argv[index[k]][j]) && argv[index[k]][j] != ' ')
					return (0);
				j++;
			}
			k++;
		}
	}
	return (1);
}

int	ft_check_input_validity(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{

		if (ft_strcmp(argv[i], "--adaptive") && ft_strcmp(argv[i], "--simple")
			&& ft_strcmp(argv[i], "--medium")
			&& ft_strcmp(argv[i], "--complex")
			&& ft_strcmp(argv[i], "--bench")
			&& !check_numstr_repetition(argv))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	//int		i;
	//int		j;
	// char	*str;

	//i = 1;
	//j = 0;
	if (argc == 1)
		return (0);
	printf("true\n");
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
}
