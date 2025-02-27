/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:53:36 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/27 11:12:10 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	find_exit_position(t_game *game)
{
	t_point	exit_pos;
	int		i;
	int		j;

	exit_pos.x = -1;
	exit_pos.y = -1;
	i = 0;
	while (i < game->map_size.y)
	{
		j = 0;
		while (j < game->map_size.x)
		{
			if (game->map[i][j] == 'E')
			{
				exit_pos.x = j;
				exit_pos.y = i;
				return (exit_pos);
			}
			j++;
		}
		i++;
	}
	return (exit_pos);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	check_file_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strcmp(filename + len - 4, ".ber") != 0)
		ft_printf("Error: Map should be in a .ber extension.\n");
	return (ft_strcmp(filename + len - 4, ".ber") == 0);
}
