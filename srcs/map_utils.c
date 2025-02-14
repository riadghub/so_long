/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:07:27 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/13 14:52:32 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_start(char **s_game)
{
	int	i;
	int	j;
	int	cstart;

	i = 0;
	cstart = 0;
	while (s_game[i])
	{
		j = 0;
		while (s_game[i][j])
		{
			if (s_game[i][j] == 'P')
				cstart++;
			j++;
		}
		i++;
	}
	if (cstart != 1)
		return (0);
	return (1);
}

int	is_valid_width(char **s_game)
{
	int	i;
	int	len;
	int	clen;

	i = 0;
	len = ft_strlen(s_game[0]);
	while (s_game[i])
	{
		clen = ft_strlen(s_game[i]);
		if (clen != len)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_content(char **s_game)
{
	int	i;
	int	j;
	int	len;
	int	clen;

	i = 0;
	len = ft_tablen(s_game);
	while (s_game[i])
	{
		j = 0;
		clen = ft_strlen(s_game[i]);
		while (s_game[i][j])
		{
			if (s_game[i][j] != '1' && s_game[i][j] != '0'
				&& s_game[i][j] != 'P' && s_game[i][j] != 'E'
				&& s_game[i][j] != 'X' && s_game[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_map(char **s_game)
{
	if (is_valid_width(s_game) && is_valid_content(s_game)
		&& is_valid_collec(s_game) && is_valid_exit(s_game)
		&& is_valid_start(s_game) && is_valid_wall(s_game))
		return (1);
	return (0);
}
