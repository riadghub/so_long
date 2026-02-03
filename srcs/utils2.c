/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 11:07:36 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/27 10:31:52 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	gamemlx(t_game *game, char *map, char *argv[])
{
	if (!game->mlx)
		return (ft_printf("Error\nFailed to initialize MiniLibX\n"), 0);
	map = read_map_file(argv[1]);
	if (!map)
		return (destroy_all(game), ft_printf("Error: Invalid map file\n"), -1);
	game->map = split_map(map);
	if (!game->map || !game->map[0] || !is_valid_map(game->map))
		return (destroy_all(game),
			ft_printf("Error: Map is empty or invalid\n"), 0);
	init_size(game);
	if (!is_map_playable(game))
		return (destroy_all(game), ft_printf("Error: Map isn't playable\n"), 0);
	if (!load_all_textures(game))
	{
		free_textures(game);
		destroy_all(game);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->map_size.x * TILE_SIZE,
			game->map_size.y * TILE_SIZE, "Dungeon Quest I");
	if (!game->win)
		return (ft_printf("Error\nFailed to create window\n"), 0);
	return (1);
}

void	free_map_copy(char **map_copy, t_point map_size)
{
	int	i;

	i = 0;
	while (i < map_size.y)
		free(map_copy[i++]);
	free(map_copy);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*str;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ptr = (unsigned char *)dest;
	str = (unsigned char *)src;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	return (dest);
}

void	print_double_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
	{
		ft_printf("Error: NULL array\n");
		return ;
	}
	while (array[i])
		ft_printf("%s\n", array[i++]);
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
