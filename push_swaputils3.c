/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaputils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:16:37 by marvin            #+#    #+#             */
/*   Updated: 2025/12/22 22:16:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printff/ft_printf.h"
#include "push_swap.h"

int	ft_isdigitt(int c)
{
	if ((c < '0' || c > '9') && c != ' ')
		return (0);
	else
		return (1);
}
char	*ft_strcpy(char *src)
{
	int		i;
	char	*dst;

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
				return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_extract_numbers(char **argv,int *index,int count)
{
	int		i;
	char	**ptr;
	int		j;

	i = 0;
	ptr = malloc((count + 1) * sizeof(char*));
	while (i < count)
	{
		j = 0;
		ptr[i] = malloc((ft_strlenn(argv[index[i]]) + 1) * sizeof(char));
		while (argv[index[i]][j])
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

void	print_two_D_array(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		ft_printf("%s\n",ptr[i++]);
}