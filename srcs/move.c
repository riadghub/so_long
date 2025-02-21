/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:26:42 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/21 13:12:56 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_empty(t_game *game, t_point map_size, t_point *pos)
{
	if (pos->x < 0 || pos->x >= map_size.x || pos->y < 0
		|| pos->y >= map_size.y)
		return (0);
	if (game->map[pos->y][pos->x] == '1')
		return (0);
	if (game->map[pos->y][pos->x] == 'E' && game->collectibles != 0)
		return (0);
	return (1);
}

void	move_up(t_game *game, t_point map_size)
{
	t_point	*temp;

	temp->x = find_player_position(game).x;
	temp->y = find_player_position(game).y - 1;
	if (is_empty(game, map_size, temp))
}
