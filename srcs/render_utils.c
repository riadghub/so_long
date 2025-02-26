/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:48:16 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/26 09:55:41 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendering(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.player, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E' && game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	rendering_right(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_right, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E' && game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	rendering_left(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_left, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E' && game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	rendering_up(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.player_up,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E' && game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	rendering_down(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_down, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E' && game->collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit, x
			* TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->textures.floor, x
			* TILE_SIZE, y * TILE_SIZE);
}
