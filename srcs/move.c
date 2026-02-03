/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:26:42 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/25 13:56:35 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_empty(t_game *game, t_point *pos)
{
	if (pos->x < 0 || pos->x >= game->map_size.x || pos->y < 0
		|| pos->y >= game->map_size.y)
		return (0);
	if (game->map[pos->y][pos->x] == '1')
		return (0);
	return (1);
}

void	move_up(t_game *game)
{
	t_point	temp;

	temp = find_player_position(game);
	temp.y -= 1;
	if (!is_empty(game, &temp))
	{
		render_map_up(game);
		return ;
	}
	first_move(game);
	if_collec(game, &temp);
	if_exit(game, &temp);
	new_player_position(game, temp);
	game->moves++;
	render_map_up(game);
	ft_printf("Moves : %d\n", game->moves);
}

void	move_down(t_game *game)
{
	t_point	temp;

	temp = find_player_position(game);
	temp.y += 1;
	if (!is_empty(game, &temp))
	{
		render_map_down(game);
		return ;
	}
	first_move(game);
	if_collec(game, &temp);
	if_exit(game, &temp);
	new_player_position(game, temp);
	game->moves++;
	render_map_down(game);
	ft_printf("Moves : %d\n", game->moves);
}

void	move_left(t_game *game)
{
	t_point	temp;

	temp = find_player_position(game);
	temp.x -= 1;
	if (!is_empty(game, &temp))
	{
		render_map_left(game);
		return ;
	}
	first_move(game);
	if_collec(game, &temp);
	if_exit(game, &temp);
	new_player_position(game, temp);
	game->moves++;
	render_map_left(game);
	ft_printf("Moves : %d\n", game->moves);
}

void	move_right(t_game *game)
{
	t_point	temp;

	temp = find_player_position(game);
	temp.x += 1;
	if (!is_empty(game, &temp))
	{
		render_map_right(game);
		return ;
	}
	first_move(game);
	if_collec(game, &temp);
	if_exit(game, &temp);
	new_player_position(game, temp);
	game->moves++;
	render_map_right(game);
	ft_printf("Moves : %d\n", game->moves);
}
