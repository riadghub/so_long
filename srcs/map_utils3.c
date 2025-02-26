/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:53:36 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/26 10:02:02 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}

t_point	find_exit_position(t_game *game)
{
	t_point	exit_pos;
	int		i;
	int		j;

	exit_pos.x = -1;
	exit_pos.y = -1;
	i = 0;
	while (i < game->map_size.y)
	{
		j = 0;
		while (j < game->map_size.x)
		{
			if (game->map[i][j] == 'E')
			{
				exit_pos.x = j;
				exit_pos.y = i;
				return (exit_pos);
			}
			j++;
		}
		i++;
	}
	return (exit_pos);
}
