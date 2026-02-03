/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:14:16 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/25 11:16:40 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

char	*part_line(char *str)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = 0;
	if (!str || *str == '\0')
		return (NULL);
	while (str[size] != '\n' && str[size] != 0)
		size++;
	res = malloc(sizeof(char) * (size + 2));
	if (!res)
		return (ft_free(str));
	while (str[i] && i <= size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*save_remaining(char *str)
{
	int		large;
	int		len;
	char	*line;

	large = 0;
	while (str[large] && str[large] != '\n')
		large++;
	if (str[large] == '\n')
		large++;
	if (str[large] == '\0')
		return (ft_free(str));
	len = 0;
	while (str[large + len])
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (ft_free(str));
	len = 0;
	while (str[large])
		line[len++] = str[large++];
	line[len] = '\0';
	free(str);
	return (line);
}

char	*read_line(int fd, char *this_line)
{
	char	*buffer;
	int		bytes_read;

	bytes_read = 1;
	if (!this_line)
	{
		this_line = malloc(1);
		if (!this_line)
			return (NULL);
		this_line[0] = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(this_line), NULL);
	while (!ft_strchr(this_line, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && this_line[0] == '\0'))
			return (free(this_line), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		this_line = ft_strjoin(this_line, buffer);
		if (!this_line)
			return (ft_free(buffer));
	}
	return (free(buffer), this_line);
}

char	*get_next_line(int fd)
{
	static char	*this_line;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	this_line = read_line(fd, this_line);
	if (!this_line)
		return (NULL);
	line = part_line(this_line);
	this_line = save_remaining(this_line);
	return (line);
}

// #include <fcntl.h>

// int main(void)
// {
//     int fd = open("test.txt", O_RDONLY);
//     char *line;

//     if (fd == -1)
//     {
//         perror("Erreur d'ouverture de fichier");
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }
