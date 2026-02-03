/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:26:23 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/27 11:40:00 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_all(t_game *game)
{
	t_point	p;

	game->player_on_exit = 0;
	game->moves = 0;
	game->collectibles = count_collectibles(game->map);
	p = find_player_position(game);
	if (p.x == -1 || p.y == -1)
	{
		ft_printf("Error: Player not found in map\n");
		exit(1);
	}
	game->player_x = p.x;
	game->player_y = p.y;
}

void	init_size(t_game *game)
{
	int	i;

	i = 0;
	game->map_size.x = 0;
	game->map_size.y = 0;
	while (game->map[game->map_size.y])
		game->map_size.y++;
	while (game->map[0][i++])
		game->map_size.x++;
}

int	handle_input(int key, t_game *game)
{
	if (key == 65307)
		close_game(game);
	if (key == MOVE_UP)
		move_up(game);
	if (key == MOVE_LEFT)
		move_left(game);
	if (key == MOVE_RIGHT)
		move_right(game);
	if (key == MOVE_DOWN)
		move_down(game);
	return (0);
}

int	close_game(t_game *game)
{
	free_textures(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (game->map)
		free_all(game->map);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	char	*map;
	int		r;

	map = NULL;
	if (argc != 2 || !check_file_extension(argv[1]))
		return (ft_printf("Usage: ./so_long <map.ber>\n"), 1);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_printf("Mlx failed to create\n"), 1);
	r = gamemlx(&game, map, argv);
	if (r != 1)
	{
		if (r == -1)
			return (1);
		return (free_all(game.map), 1);
	}
	init_all(&game);
	render_map(&game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_input, &game);
	mlx_loop(game.mlx);
	free_all(game.map);
	free_textures(&game);
	return (0);
}
