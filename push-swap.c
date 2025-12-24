/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzahredd <nzahredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:23:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/24 19:56:13 by nzahredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printff/ft_printf.h"
#include "push_swap.h"

// t_node ft_list_extract()
// void push_swap(t_node a, char **argv)
// {
	
// }
char *extract_startegy(char **argv)
{
	char strategy[10];
	int i;

	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--simple"))
			return ("--simple");
		else if (ft_strcmp(argv[i], "--medium"))
			return ("--medium");
		else if (ft_strcmp(argv[i], "--complex"))
			return ("--complex");
		else if (ft_strcmp(argv[i], "--adaptive"))
			return ("--adaptive");
		i++;
	}
	return (NULL);
}
void check_strategy(char **argv)
{
	char *strategy;

	strategy = extract_startegy(argv);
	if (ft_strcmp(strategy, "--simple"))
		simple_algo();
	else if (ft_strcmp(strategy, "--medium"))
		medium_algo();
	else if (ft_strcmp(strategy, "--complex"))
		complex_algo();
	else if (ft_strcmp(strategy, "--adaptive") || strategy == NULL)
		adaptive_algo();
}

// int	main(int argc, char **argv)
// {
// 	//int		i;
// 	//int		j;
// 	char	**ptr;
// 	t_node a;

// 	//i = 1;
// 	//j = 0;
// 	if (argc == 1)
// 		return (0);
// 	if (!ft_check_input_validity(argv, ptr))
// 	{
// 		ft_printf("error");
// 		ft_printf("\n");
// 		return (0);
// 	}
// 	a = ft_list_extract(ptr);
// 	push_swap(a);
// 	printf("true\n");
// 	// str = ft_extract_str_numbers(argc, argv);
// 	// j = search_strategy_existance(argv);
// 	// if (j == 0 || ft_strcmp(str,"adaptive") == 0)
// 	// 	ft_adaptive_process(str);
// 	// else
// 	// 	ft_Other_process(str);
// 	// if(search_bench_existance(argv))
// 	// 	ft_bench_process();
// 	return (0);
// }
