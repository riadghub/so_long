/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:26:16 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/26 09:58:18 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			rendering(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_map_right(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			rendering_right(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_map_left(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			rendering_left(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_map_down(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			rendering_down(game, x, y);
			x++;
		}
		y++;
	}
}

void	render_map_up(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_size.y)
	{
		x = 0;
		while (x < game->map_size.x)
		{
			rendering_up(game, x, y);
			x++;
		}
		y++;
	}
}
