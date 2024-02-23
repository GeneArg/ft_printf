/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:19:40 by eagranat          #+#    #+#             */
/*   Updated: 2024/02/23 18:38:31 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
	{
		count += print_unsigned(n / 10);
		c = (n % 10) + '0';
		count += write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int	print_int(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
		count += write(1, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	else if (n >= 10)
	{
		count += print_int(n / 10);
		c = (n % 10) + '0';
		count += write(1, &c, 1);
	}
	else if (n >= 0 && n < 10)
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	return (count);
}

int	print_hex(unsigned long long n, int upper)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 16)
	{
		count += print_hex(n / 16, upper);
		count += print_hex(n % 16, upper);
	}
	else
	{
		if (n < 10)
		{
			c = n + '0';
			count += write(1, &c, 1);
		}
		else
		{
			if (upper)
				count += write(1, &"0123456789ABCDEF"[n % 16], 1);
			else
				count += write(1, &"0123456789abcdef"[n % 16], 1);
		}
	}
	return (count);
}
