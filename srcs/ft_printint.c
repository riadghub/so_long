/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:32:57 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/25 10:30:33 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putchar_final(char t[], int point, int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
	}
	while (point >= 0)
	{
		ft_putchar(t[point--] + '0');
	}
}

int	ft_putchar_zero(int nb)
{
	if (nb == 0)
		return (ft_putchar('0'));
	return (0);
}

int	ft_putnbr(int n)
{
	long long	nb;
	int			point;
	int			res;
	char		t[12];

	point = 0;
	res = 0;
	nb = n;
	res += ft_putchar_zero(nb);
	if (nb < 0)
	{
		nb *= -1;
		res += ft_putchar('-');
	}
	while (nb > 0)
	{
		t[point++] = nb % 10;
		res++;
		nb /= 10;
	}
	ft_putchar_final(t, point - 1, 1);
	return (res);
}

int	ft_uputnbr(unsigned int n)
{
	unsigned long long	nb;
	int					point;
	int					res;
	char				t[12];

	point = 0;
	res = 0;
	nb = n;
	res += ft_putchar_zero(nb);
	while (nb > 0)
	{
		t[point++] = nb % 10;
		res++;
		nb /= 10;
	}
	ft_putchar_final(t, point - 1, 1);
	return (res);
}
