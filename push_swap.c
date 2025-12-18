/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 08:23:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/17 08:23:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf/ft_printf.h"
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
float ft_compute_disorder(int *a,int size);//required by subject found in utils
void ft_check_disorder(int *a);// we use the compute_disorder inside it. This function to know which algo we should use.it should be used in the Other_process function
void ft_bench_process(void);
int search_bench_existance(char **argv);

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
	int a[]={0,1,2,1,2,1,2};
	int number=ft_compute_disorder(a,7);
	ft_printf("%d\n",number);
}
/*Nour, see the --bench remarks in the pdf and continue the following main only, you can use prototypes' methods as I did, step by step
we finish the project*/
//The prototypes' method is used only for planning