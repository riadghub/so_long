/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:49:55 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/24 11:12:11 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **map, t_point size, t_point start)
{
	if (start.x < 0 || start.x >= size.x || start.y < 0 || start.y >= size.y)
		return ;
	if (map[start.y][start.x] == '1' || map[start.y][start.x] == 'F')
		return ;
	map[start.y][start.x] = 'F';
	flood_fill(map, size, (t_point){start.x - 1, start.y});
	flood_fill(map, size, (t_point){start.x + 1, start.y});
	flood_fill(map, size, (t_point){start.x, start.y - 1});
	flood_fill(map, size, (t_point){start.x, start.y + 1});
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin);
}

int	check_remaining_elements(char **map_copy, t_point map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size.y)
	{
		j = 0;
		while (j < map_size.x)
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E'
				|| map_copy[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
