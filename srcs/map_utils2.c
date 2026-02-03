/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:10:39 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/26 11:57:23 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_size.y)
	{
		j = 0;
		while (j < game->map_size.x)
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

void	update_player_position(t_game *game, t_point pos, char c)
{
	if (game->player_on_exit == 1)
	{
		game->map[game->player_y][game->player_x] = 'E';
		game->player_on_exit = 0;
	}
	else
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = pos.x;
	game->player_y = pos.y;
	game->map[game->player_y][game->player_x] = 'P';
	if (c == 'E')
		game->player_on_exit = 1;
}

void	new_player_position(t_game *game, t_point pos)
{
	t_point	p;
	char	c;

	if (game->player_x < 0 || game->player_y < 0
		|| game->player_y >= game->map_size.y
		|| game->player_x >= game->map_size.x)
	{
		p = find_player_position(game);
		game->player_x = p.x;
		game->player_y = p.y;
	}
	if (pos.x < 0 || pos.x >= game->map_size.x || pos.y < 0
		|| pos.y >= game->map_size.y)
		return ;
	c = game->map[pos.y][pos.x];
	update_player_position(game, pos, c);
}

t_point	find_player_position(t_game *game)
{
	t_point	player_pos;
	int		i;
	int		j;

	player_pos.x = -1;
	player_pos.y = -1;
	i = 0;
	while (i < game->map_size.y)
	{
		j = 0;
		while (j < game->map_size.x)
		{
			if (game->map[i][j] == 'P')
			{
				player_pos.x = j;
				player_pos.y = i;
				return (player_pos);
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}

int	is_map_playable(t_game *game)
{
	char	**map_copy;
	t_point	player_pos;
	int		is_valid;

	map_copy = copy_map(game->map, game->map_size);
	if (!map_copy)
		return (0);
	player_pos = find_player_position(game);
	if (player_pos.x == -1 || player_pos.y == -1)
	{
		free_map_copy(map_copy, game->map_size);
		return (0);
	}
	flood_fill(map_copy, game->map_size, player_pos);
	is_valid = check_remaining_elements(map_copy, game->map_size);
	free_map_copy(map_copy, game->map_size);
	return (is_valid);
}
