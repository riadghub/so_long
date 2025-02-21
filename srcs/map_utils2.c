/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:10:39 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/21 13:07:37 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			j++;
		}
		i++;
	}
}

t_point	find_player_position(t_game *game)
{
	t_point	player_pos;
	int		i;
	int		j;

	player_pos.x = -1;
	player_pos.y = -1;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				player_pos.x = i;
				player_pos.y = j;
				return (player_pos);
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}

int	is_map_playable(t_game *game, t_point map_size)
{
	char	**map_copy;
	t_point	player_pos;
	int		is_valid;

	map_copy = copy_map(game->map, map_size);
	if (!map_copy)
		return (0);
	player_pos = find_player_position(game);
	if (player_pos.x == -1 || player_pos.y == -1)
	{
		free_map_copy(map_copy, map_size);
		return (0);
	}
	flood_fill(map_copy, map_size, player_pos);
	is_valid = check_remaining_elements(map_copy, map_size);
	free_map_copy(map_copy, map_size);
	return (is_valid);
}

int	count_collectibles(char **s_game)
{
	int	i;
	int	j;
	int	ccount;

	i = 0;
	ccount = 0;
	while (s_game[i])
	{
		j = 0;
		while (s_game[i][j])
		{
			if (s_game[i][j] == 'C')
				ccount++;
			j++;
		}
		i++;
	}
	return (ccount);
}
