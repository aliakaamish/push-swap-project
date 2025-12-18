/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakaamis <aakaamis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:14:16 by aakaamis          #+#    #+#             */
/*   Updated: 2025/11/21 20:35:16 by aakaamis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "limits.h"

int		write_string(const char *sentence, int *i);
int		ft_int_print(va_list args);
int		ft_string_print(va_list args);
int		ft_printchar(char c);
int		convert_to_hexadecimal(unsigned long n, int x);
int		ft_address_print_p(va_list args, int x);
int		ft_address_print_x(va_list args, int x);
int		ft_unsigned_int_print(va_list args);
int		ft_string_iterate_check(const char *sentence, va_list args, int index);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int		ft_printf(const char	*sentence, ...);
void	ft_putnbr_fd(unsigned int n, int fd);
int		length_of_int(unsigned int x);

#endif