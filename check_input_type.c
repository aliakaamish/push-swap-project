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

int ft_strchr(char *s, int c)
{
    int count_spaces;

    count_spaces = 0;
    while (*s)
    {
        if (*s == (char)c)
            count_spaces++;
        s++;
    }
        return (count_spaces);
}

int ft_input_type(char **argv)
{
    int i = 1;
    int count_strategy = 0;
    int count_bench = 0;
    int count_numbers = 0;
    int has_space = 0;

    while (argv[i])
    {
        if (!ft_strcmp(argv[i], "--simple")
            || !ft_strcmp(argv[i], "--complex")
            || !ft_strcmp(argv[i], "--medium")
            || !ft_strcmp(argv[i], "--adaptive"))
            count_strategy++;

        else if (!ft_strcmp(argv[i], "--bench"))
            count_bench++;

        else if (ft_isdigit(argv[i][0]) || argv[i][0] == '-' || argv[i][0] == '+')
        {
            count_numbers++;
            if (ft_strchr(argv[i], ' '))
                has_space++;
        }
        i++;
    }

    printf("has_space=%d\n",has_space);
    // ❌ more than one flag
    if (count_strategy > 1 || count_bench > 1)
        return (0);

    printf("count_numbers=%d\n",count_numbers);
    // ❌ mixed input
    if (has_space >= 1 && count_numbers > 1)
        return (0);
    return (1);
}
