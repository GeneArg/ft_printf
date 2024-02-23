/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:33:11 by eagranat          #+#    #+#             */
/*   Updated: 2024/02/23 19:10:28 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		print_char(char c);
int		print_string(char *s);
int		print_pointer(void *p);
int		print_int(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned long long n, int upper);
int		ft_printf(const char *format, ...);
int		print_format(char c, va_list ap);

#endif