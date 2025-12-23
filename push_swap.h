/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:49:05 by aakaamis          #+#    #+#             */
/*   Updated: 2025/12/23 09:06:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>

float		ft_compute_disorder(int *a, int len);
int			ft_isdigitt(int c);
int			ft_atoi(char *nptr);
float		ft_compute_disorder(int *a, int len);
int			ft_strcmp(char *s1, char *s2);
int			check_duplicate(char **str);
int			count_mblocks(char **argv, int **index);
int			check_numstr_repetition(char **argv);
char		*ft_strcpy(char *src);
int			check_numbers_validation(char *str);
int			ft_check_input_validity(char **argv);
long long	ft_atoi_advanced(char *nptr);
char		**ft_split(char *s, char c);
void		ft_O_n_squared(void);
void		ft_O_n_redical_n(void);
void		ft_O_nlogn(void);
void		ft_adaptive(void);
int			search_strategy_existance(char **argv);
void		ft_adaptive_process(char *str);
void		ft_Other_process(char *str);
int			*ft_extract_str(int argc, char **argv);
void		ft_check_disorder(int disorder);
void		ft_bench_process(void);
int			search_bench_existance(char **argv);
char		*ft_extract_str_numbers(int argc, char **argv);
int			ft_input_type(char **argv);
char		**ft_extract_numbers(char **argv, int *index, int count);
void		print_two_D_array(char **ptr);

#endif