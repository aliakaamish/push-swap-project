/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 10:00:24 by marvin            #+#    #+#             */
/*   Updated: 2025/12/21 10:00:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printff/ft_printf.h"
#include "push_swap.h"

/*char	*ft_strdup(char *s)
{
	char	*copy;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	copy = (char *)malloc((len + 1));
	if (copy == NULL)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

long long	ft_atoi_long(char *nptr)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;

	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}

	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
int number_counter(char **argv)
{
	int i;
	int j;
	int count;
	char **new;

	i = 1;
	count = 0;
	while (argv[i])
	{
		j = 0;
		new = ft_split(argv[i], ' ');
		if (!new)
			return (0);
		while (new[j])
		{
			count++;
			free(new[j]);
			j++;
		}
		i++;
		free(new);
	}
	return (count);
}
char **extract_numbers(char **argv)
{
	char **result;
	char **extracted;
	int i;
	int j;
	int n;

	result = malloc((number_counter(argv) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	n = 0;
	while (argv[++i])
	{
		extracted = ft_split(argv[i], ' ');
		j = -1;
		while (extracted[++j])
		{
			if (extracted[j][0] != '\0')
				result[n++] = ft_strdup(extracted[j]);
			free(extracted[j]);
		}
	}
	free(extracted);
	result[n] = NULL;
	return (result);
}
int	is_validnum(char *str)
{
	int i;
	long long num;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	num = ft_atoi_long(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}
int num_validation(char **argv)
{
	int	i;
	char **num;

	num = extract_numbers(argv);


	i = 0;
	while (num[i])
	{
		if (!is_validnum(num[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;	
	}
	if (!check_duplicate(num))
	{
		ft_printf("Error\n");
		return (0);
	}
		return (1);
}
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("No numbers provided.\n");
        return 0;
    }

    if (!num_validation(argv))
    {
        ft_printf("Validation failed.\n");
        return 1;
    }

    ft_printf("All numbers are valid and no duplicates found.\n");
    return 0;
}
*/