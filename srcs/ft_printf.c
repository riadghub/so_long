/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 08:21:34 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/25 10:30:29 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_case(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_printptr(va_arg(args, unsigned long)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_uputnbr(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_printhex(va_arg(args, unsigned int), 0));
	if (c == 'X')
		return (ft_printhex(va_arg(args, unsigned int), 1));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		res;
	va_list	args;

	i = 0;
	res = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			res += ft_case(str[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}

// #include <stdio.h>
// int	main(void)
// {
// 	long LONG_MIN = -2147483647 - 1;
// 	long LONG_MAX = 2147483647;
// 	printf("printf : %p", LONG_MIN);
// 	ft_putchar('\n');
// 	ft_printf("ft_printf : %p", LONG_MIN);
// 	return (0);
// }
