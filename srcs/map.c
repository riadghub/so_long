/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:00:31 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/27 10:50:05 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**split_map(char *map_str)
{
	char	**map;

	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}

char	*read_map_file(char *file)
{
	int		fd;
	char	*line;
	char	*map;
	char	*temp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (close(fd), NULL);
	map = ft_strdup("");
	if (!map)
		return (close(fd), NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		temp = ft_strjoin(map, line);
		if (!temp)
			continue ;
		map = temp;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}

int	is_valid_wall(char **s_game)
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
			if (s_game[0][j] != '1' || s_game[len - 1][j] != '1'
				|| s_game[i][0] != '1' || s_game[i][clen - 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_exit(char **s_game)
{
	int	i;
	int	j;
	int	cexit;

	i = 0;
	cexit = 0;
	while (s_game[i])
	{
		j = 0;
		while (s_game[i][j])
		{
			if (s_game[i][j] == 'E')
				cexit++;
			j++;
		}
		i++;
	}
	if (cexit != 1)
		return (0);
	return (1);
}

int	is_valid_collec(char **s_game)
{
	int	i;
	int	j;
	int	cc;

	i = 0;
	cc = 0;
	while (s_game[i])
	{
		j = 0;
		while (s_game[i][j])
		{
			if (s_game[i][j] == 'C')
				cc++;
			j++;
		}
		i++;
	}
	if (cc < 1)
		return (0);
	return (1);
}
