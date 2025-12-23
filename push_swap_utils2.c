/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:34:36 by aakaamis          #+#    #+#             */
/*   Updated: 2025/12/23 21:07:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	number_of_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] == c && s[i])
				i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	check_char_matching(char *s, char c, int i)
{
	return (s[i] == c);
}

static int	length_of_word(char *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i + count] && !check_char_matching(s, c, i + count))
		count++;
	return (count);
}

static void	fill_word(char **ptr, char *s, char c, int *i)
{
	int	j;
	int	length;

	j = 0;
	length = length_of_word(s, c, *i);
	ptr[0] = malloc(length + 1);
	while (j < length)
		ptr[0][j++] = s[(*i)++];
	ptr[0][j] = '\0';
}

char	**ft_split(char *s, char c)
{
	char	**ptr;
	int		i;
	int		row;

	i = 0;
	row = 0;
	ptr = malloc(sizeof(char *) * (number_of_words(s, c) + 1));
	ptr[number_of_words(s, c)] = 0;
	while (s[i])
	{
		if (!check_char_matching(s, c, i))
		{
			fill_word(&ptr[row], s, c, &i);
			row++;
		}
		else
			i++;
	}
	return (ptr);
}
