/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:23:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/18 14:14:18 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printff/ft_printf.h"
#include "push_swap.h"
//only added 2 prototypes and the compute_disorder function

//still you need to implement the ft_printf function that you did.
void ft_O_n_squared(void);
void ft_O_n_redical_n(void);
void ft_O_nlogn(void);
void ft_adaptive(void);
int ft_check_input_validity(char **argv);//check duplicates, not integers, integers outside the valid range
int search_strategy_existance(char **argv);
void ft_adaptive_process(int *str);
void ft_Other_process(int *str);
int *ft_extract_str(int argc,char **argv);//in this function you should use the split and the atoi.
float	ft_compute_disorder(int *a,int size);//required by subject found in utils
void	ft_check_disorder(int *a);// we use the compute_disorder inside it. This function to know which algo we should use.it should be used in the Other_process function
void	ft_bench_process(void);
int		search_bench_existance(char **argv);
int		ft_strcmp(char *str, char *ptr);

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
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
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
		while (!ft_isdigit(argv[i][j]))
			j++;
		if (j != ft_strlen(argv[i]))
			count++;
		i++;
	}
	*index = malloc(count * sizeof(int));
	i = 0;
	while (argv[i])
	{
		j = 0;
		while (!ft_isdigit(argv[i][j]))
			j++;
		if (j != ft_strlen(argv[i]))
			(*index)[k++] = i;
		i++;
	}
	return (count);
}


int	check_numstr_repetition(char **argv)
{
	int	i;
	int	j;
	int	*index;
	int	k;

	i = 0;
	k = 0;
	if (count_mblocks(argv, &index) == 1)
	{
		if (!ft_isdigit(argv[index[0]][0])
			|| !ft_isdigit(argv[index[0]][ft_strlenn(argv[index[0]]) - 1]))
			return (0);
		while (argv[index[0]][i])
		{
			if (!ft_isdigit(argv[index[0]][i]) && argv[index[0]][i] != ' ')
				return (0);
			i++;
		}
	}
	else
	{
		while (k < count_mblocks(argv, index))
		{
			if (!ft_isdigit(argv[index[k]][0])
			|| !ft_isdigit(argv[index[k]][ft_strlenn(argv[index[k]]) - 1]))
				return (0);
			while (argv[index[k]][i])
			{
				if (!ft_isdigit(argv[index[k]][i]) && argv[index[k]][i] != ' ')
					return (0);
				i++;
			}
			k++;
		}
	}
	return (1);
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
		return (0);
	if (ft_strcmp(int_max, str) < 0)
		return (0);
	if (ft_strcmp(int_min, str) > 0)
		return (0);
	while (str[i++])
	{
		if (ft_isdigit(str[i]))
		{
			if (str[i] == '-' || str[i] == '+')
			{
				i++;
				if (!ft_isdigit(str[i]))
					return (0);
			}
			return (0);
		}
	}
	return (1);
}

int	ft_check_input_validity(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "--adaptive") && !ft_strcmp(argv[i], "--simple")
			&& !ft_strcmp(argv[i], "--medium")
			&& !ft_strcmp(argv[i], "--complex")
			&& !ft_strcmp(argv[i], "--bench")
			&& !check_numbers_validation(argv[i])
			&& !check_numstr_repetition(argv[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	*str;

	i = 1;
	j = 0;
	if (argc == 1)
		return (0);
	if (!ft_check_input_validity(argv));
	{
		ft_printf("error");
		return (0);
	}
	//after here, the 2D array argv is valid, it contains numbers,strategy type,and the ./a.out, it also contains the --bench but after we finish the main concepts we will continue this selection!!
	//remember from now on the numbers are valid don't be hesitant.
	str = ft_extract_str_numbers(argc, argv);//str contains the numbers that we apply on in the functions below.
	j = search_strategy_existance(argv);//if j == 0 then no strategy is assigned.
	if (j == 0 || argv[j] == "adaptive")//j == 0 --> no strategy exists
		ft_adaptive_process(str);
	else
		ft_Other_process(str);
	if(search_bench_existance(argv))
		ft_bench_process();
	return (0);
}
/*Nour, see the --bench remarks in the pdf and continue the following main only, you can use prototypes' methods as I did, step by step
we finish the project*/
//The prototypes' method is used only for planning