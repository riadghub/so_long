/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:09:31 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/27 10:30:12 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_all(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printhex(unsigned long long n, int maj)
{
	int		res;
	char	*base;

	res = 0;
	if (maj == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n <= 15)
		ft_putchar(base[n]);
	if (n > 15)
	{
		res += ft_printhex(n / 16, maj);
		ft_putchar(base[n % 16]);
	}
	return (res + 1);
}

int	ft_printptr(unsigned long long p)
{
	int	res;

	res = 0;
	if (p == 0)
		return (ft_putstr("(nil)"));
	res += ft_putstr("0x");
	res += ft_printhex(p, 0);
	return (res);
}
