/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:20:19 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/25 12:10:11 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_texture(void *mlx, char *path)
{
	int		width;
	int		height;
	void	*texture;

	texture = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!texture)
	{
		ft_printf("Error\nFailed to load texture.\n");
		exit(1);
	}
	return (texture);
}

void	load_all_textures(t_game *game)
{
	game->textures.wall = load_texture(game->mlx, "xpm/wall.xpm");
	game->textures.player = load_texture(game->mlx,
			"xpm/character_down_idle.xpm");
	game->textures.player_down = load_texture(game->mlx,
			"xpm/character_down_move.xpm");
	game->textures.player_left = load_texture(game->mlx,
			"xpm/character_left_move.xpm");
	game->textures.player_right = load_texture(game->mlx,
			"xpm/character_right_move.xpm");
	game->textures.player_up = load_texture(game->mlx,
			"xpm/character_up_move.xpm");
	game->textures.collectible = load_texture(game->mlx, "xpm/chest.xpm");
	game->textures.exit = load_texture(game->mlx, "xpm/exit.xpm");
	game->textures.floor = load_texture(game->mlx, "xpm/tile.xpm");
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
