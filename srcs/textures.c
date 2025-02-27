/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:20:19 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/27 10:27:52 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_texture(void *mlx, char *path)
{
	int		width;
	int		height;
	void	*texture;

	texture = mlx_xpm_file_to_image(mlx, path, &width, &height);
	return (texture);
}

int	load_all_textures(t_game *game)
{
	game->textures.wall = load_texture(game->mlx, WALL_PATH);
	game->textures.player = load_texture(game->mlx, PLAYER_PATH);
	game->textures.player_down = load_texture(game->mlx, PLAYER_DOWN_PATH);
	game->textures.player_left = load_texture(game->mlx, PLAYER_LEFT_PATH);
	game->textures.player_right = load_texture(game->mlx, PLAYER_RIGHT_PATH);
	game->textures.player_up = load_texture(game->mlx, PLAYER_UP_PATH);
	game->textures.collectible = load_texture(game->mlx, CHEST_PATH);
	game->textures.exit = load_texture(game->mlx, EXIT_PATH);
	game->textures.floor = load_texture(game->mlx, FLOOR_PATH);
	if (!game->textures.collectible || !game->textures.wall
		|| !game->textures.player || !game->textures.player_down
		|| !game->textures.player_left || !game->textures.player_right
		|| !game->textures.player_up || !game->textures.exit
		|| !game->textures.floor)
	{
		ft_printf("Error\nFailed to load texture.\n");
		return (0);
	}
	return (1);
}

void	free_textures(t_game *game)
{
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	if (game->textures.player_down)
		mlx_destroy_image(game->mlx, game->textures.player_down);
	if (game->textures.player_left)
		mlx_destroy_image(game->mlx, game->textures.player_left);
	if (game->textures.player_right)
		mlx_destroy_image(game->mlx, game->textures.player_right);
	if (game->textures.player_up)
		mlx_destroy_image(game->mlx, game->textures.player_up);
	if (game->textures.collectible)
		mlx_destroy_image(game->mlx, game->textures.collectible);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
}
