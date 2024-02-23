/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagranat <eagranat@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:42:12 by eagranat          #+#    #+#             */
/*   Updated: 2024/02/23 19:09:55 by eagranat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_char(char c)
{
	int	count;
	
	count = 0;
	count += write(1, &c, 1);
	return (count);
}
int	print_string(char *s)
{
	int	count;

	count = 0;
	while (*s)
		count += write(1, s++, 1);
	return (count);
}

int	print_pointer(void *p)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	count += print_hex((unsigned long long)p, 0);
	return (count);
}

int	print_format(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += print_char(va_arg(ap, int));
	else if (c == 's')
		count += print_string(va_arg(ap, char *));
	else if (c == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		count += print_int(va_arg(ap, int));
	else if (c == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x')
		count += print_hex(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
		count += print_hex(va_arg(ap, unsigned int), 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				count += write(1, &format[i], 1);
			else if (format[i] != '\0')
				count += print_format(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

int main()
{
	int a = 42;
    int *p = &a;
    int **pp = &p;

    ft_printf("");
    printf("");
	printf("--------------------\n");
    //ft_printf("%i\n", INT_MAX);
    //printf("%i\n", INT_MAX);
	//printf("--------------------\n");
    //ft_printf("%d\n", INT_MIN);
    //printf("%d\n", INT_MIN);
	//printf("--------------------\n");
    ft_printf("%s\n", "Hello, \nWorld!");
    printf("%s\n", "Hello, \nWorld!");
	printf("--------------------\n");
    ft_printf("%s\n", "Hello, %s\n");
    printf("%s\n", "Hello, %s\n");
	printf("--------------------\n");
    ft_printf("Hello, %s. The answer is %d.\n", "World", 42);
    printf("Hello, %s. The answer is %d.\n", "World", 42);
	printf("--------------------\n");
    ft_printf("%p\n", &printf);
    printf("%p\n", &printf);
	printf("--------------------\n");
    ft_printf("%p\n", pp);
    printf("%p\n", pp);
	printf("--------------------\n");
    ft_printf("Hello, %%\n");
    printf("Hello, %%\n");
	printf("--------------------\n");
	ft_printf("%x\n", 42);
	printf("%x\n", 42);
	printf("--------------------\n");
	ft_printf("%X\n", 42);
	printf("%X\n", 42);
	printf("--------------------\n");
	ft_printf("%u\n", -42);
	printf("%u\n", -42);
	printf("--------------------\n");
	ft_printf("%c\n", 'c');
	printf("%c\n", 'c');
	printf("--------------------\n");
	ft_printf("%d\n", 000000);
	printf("%d\n", 000000);

    return 0;
}
