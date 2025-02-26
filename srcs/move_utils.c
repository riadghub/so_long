/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:53:36 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/25 10:13:20 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_move(t_game *game)
{
	t_point	temp;

	temp = find_player_position(game);
	if (game->moves == 0)
		game->map[temp.y][temp.x] = '0';
}

void	if_collec(t_game *game, t_point *pos)
{
	if (pos->x < 0 || pos->x >= game->map_size.x || pos->y < 0
		|| pos->y >= game->map_size.y)
		return ;
	if (game->map[pos->y][pos->x] == 'C')
		game->collectibles--;
}

void	if_exit(t_game *game, t_point *pos)
{
	if (pos->x < 0 || pos->x >= game->map_size.x || pos->y < 0
		|| pos->y >= game->map_size.y)
		return ;
	if (game->map[pos->y][pos->x] == 'E' && game->collectibles == 0)
		close_game(game);
}
