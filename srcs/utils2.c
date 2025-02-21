/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:07:36 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/20 11:25:18 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_copy(char **map_copy, t_point map_size)
{
	int	i;

	i = 0;
	while (i < map_size.y)
		free(map_copy[i++]);
	free(map_copy);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*str;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ptr = (unsigned char *)dest;
	str = (unsigned char *)src;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	return (dest);
}

void	print_double_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
	{
		printf("Error: NULL array\n");
		return ;
	}
	while (array[i])
		printf("%s\n", array[i++]);
}
