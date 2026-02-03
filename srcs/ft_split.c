/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:25:55 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/03/01 11:48:49 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(char **map)
{
	int	i;

	if (!map || !*map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	count_words(const char *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			res++;
		i++;
	}
	return (res);
}

char	*get_word(char const *str, char c, int *index)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[*index] == c && str[*index])
		(*index)++;
	while (str[*index + j] && str[*index + j] != c)
		j++;
	res = malloc(sizeof(char) * (j + 1));
	if (!res)
		return (free(res), NULL);
	while (i < j)
	{
		res[i] = str[*index];
		i++;
		(*index)++;
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !*s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (free_all(res), NULL);
	while (j < count_words(s, c))
	{
		res[j] = get_word(s, c, &i);
		j++;
	}
	res[j] = 0;
	return (res);
}
