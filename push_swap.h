/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzahredd <nzahredd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:49:05 by aakaamis          #+#    #+#             */
/*   Updated: 2025/12/24 17:47:29 by nzahredd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>


typedef struct t_node
{
	int			value;
	struct t_node	*next;
	struct t_node	*previous;
}t_node;

typedef struct t_stack
{
	t_node *top;
}t_stack;

float		ft_compute_disorder(int *a, int len);
int			ft_isdigitt(int c);
int			ft_atoi(char *nptr);
float		ft_compute_disorder(int *a, int len);
int			ft_strcmp(char *s1, char *s2);
int			check_duplicate(char **str);
int			count_mblocks(char **argv, int **index);
int			check_numstr_repetition(char **argv, char ***ptr);
char		*ft_strcpy(char *src);
int			check_numbers_validation(char *str);
int			ft_check_input_validity(char **argv, char **ptr);
long long	ft_atoi_advanced(char *nptr);
char		**ft_split(char *s, char c);
int			ft_input_type(char **argv);
char		**ft_extract_numbers(char **argv, int *index, int count);
void		print_two_D_array(char **ptr);
void		check_minus_signs(char **s1, char **s2);

#endif