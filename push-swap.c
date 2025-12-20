/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:23:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/20 10:33:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printff/ft_printf.h"
#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
		{
			if(s1[i] == '+' && ft_isdigit(s2[j]))
			{
				i++;
				continue;
			}	
			else if(s2[j] == '+' && ft_isdigit(s1[i]))
			{
				j++;
				continue;
			}
			else
			{
				return (s1[i] - s2[i]);
			}
		}
		i++;
		j++;
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
	j = 0;
	while(argv[i] && argv[i][j])
	{
		if(ft_isdigitt(argv[i][j]))
		{
			count++;
			i++;
			j = 0;
		}
		else
		{
			j++;
			if(!argv[i][j])
			{
				j = 0;
				i++;
			}
		}
	}
	printf("%d\n",count);
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

char	**ft_extract_numbers(char **argv,int *index,int count)
{
	int i;
	char **ptr;
	int j;

	i = 0;
	ptr = malloc((count + 1) * sizeof(char*));
	while(i < count)
	{
		j = 0;
		ptr[i] = malloc((ft_strlenn(argv[index[i]]) + 1) * sizeof(char));
		while(argv[index[i]][j])
		{
			ptr[i][j] = argv[index[i]][j];
			j++;
		}
		ptr[i][j] = '\0';
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

void print_two_D_array(char **ptr)
{
	int i;

	i = 0;
	while(ptr[i])
	{
		printf("%s\n",ptr[i++]);
	}
}

int	check_numstr_repetition(char **argv)
{
	int	j;
	int	*index;
	char **ptr;
	int	count;
	int	k;

	j = 0;
	k = 0;
	count = count_mblocks(argv, &index);
	printf("count=%d\n",count);
	if(count == 1)
	{
		if (!(argv[index[k]][0] - ' ')
			|| !ft_strcmp(&argv[index[k]][ft_strlenn(argv[index[k]]) - 1], " "))
			return (0);
		ptr=ft_split(argv[index[k]], ' ');
	}
	else
	{
		ptr=ft_extract_numbers(argv,index,count);
	}
	if(!ft_input_type(argv) || !check_duplicate(ptr))
	{
		free (index);
		free (ptr);
		return (0);
	}
	print_two_D_array(ptr);
	printf("count=%d",count);
	while (k < count)
	{
		j = 0;
		printf("in k = %d\n",k);
		while (ptr[k][j])
		{
			if (!ft_isdigitt(ptr[k][j])
				&& ptr[k][j] != '+' && ptr[k][j] != '-' )
			{
				printf("here\n");
				return (0);
			}
			if(ptr[k][j] == ' ' && !ft_isdigit(ptr[k][j + 1])
				&& ptr[k][j + 1] != '+' && ptr[k][j + 1] != '-')
			{
				printf("here\n");
				return (0);
			}
			if((ptr[k][j] == '+' || ptr[k][j] == '-'))
			{
				j++;
				while(ptr[k][j] != ' ' && ptr[k][j])
				{
					if(!ft_isdigit(ptr[k][j]))
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
		j = 0;
		printf("before split\n");
		while(ptr[j])
		{
			if(!check_numbers_validation(ptr[j]))
			{
				printf("split\n");
				return (0);
			}
			j++;
		}
		k++;
	}
	return (1);
}

int check_strategies(char *argv)
{
	int i;
	int  count_digits;

	i = 0;
	count_digits = 0;
	if(ft_strcmp(argv, "--adaptive") && ft_strcmp(argv, "--simple")
			&& ft_strcmp(argv, "--medium")
			&& ft_strcmp(argv, "--complex")
			&& ft_strcmp(argv, "--bench"))
	{
		while(argv[i])
		{
			if(ft_isdigit(argv[i]))
				count_digits++;
			i++;
		}
		if(count_digits == 0)
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
			return(0);
		}
		if(!check_numstr_repetition(argv))
			return(0);
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
