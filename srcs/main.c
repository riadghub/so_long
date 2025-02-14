/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:26:23 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/13 14:10:56 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_game *game)
{
	if (key == 65307)
		close_game(game);
	return (0);
}

int	close_game(t_game *game)
{
	free_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	char	*map;
	int		i;

	i = 0;
	if (argc != 2)
	{
		printf("Usage: ./so_long <map.ber>\n");
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
		return (printf("Error\nFailed to initialize MiniLibX\n"), 1);
	map = read_map_file(argv[1]);
	if (!map)
		return (printf("Error: Invalid map file\n"), 1);
	game.map = split_map(map);
	if (!game.map || !game.map[0] || !is_valid_map(game.map))
		return (printf("Error: Map is empty or invalid\n"), 1);
	game.map_height = 0;
	game.map_width = 0;
	while (game.map[game.map_height])
		game.map_height++;
	while (game.map[0][i++])
		game.map_width++;
	load_all_textures(&game);
	game.win = mlx_new_window(game.mlx, game.map_width * TILE_SIZE,
			game.map_height * TILE_SIZE, "Dungeon Quest I");
	if (!game.win)
		return (printf("Error\nFailed to create window\n"), 1);
	render_map(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_loop(game.mlx);
	free_textures(&game);
	return (0);
}
