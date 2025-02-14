/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:43:11 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/14 10:33:44 by reeer-aa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "mlx_int.h"
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 48
# define OPEN 1
# define CLOSED 0

typedef struct s_game	t_game;
typedef struct s_node	t_node;

typedef struct s_textures
{
	void				*wall;
	void				*player;
	void				*collectible;
	void				*exit;
	void				*enemy;
	void				*floor;
}						t_textures;

struct					s_game
{
	void				*mlx;
	void				*win;
	t_textures			textures;
	char				**map;
	int					map_width;
	int					map_height;
	int					player_x;
	int					player_y;
	int					collectibles;
};

struct					s_node
{
	char				type;
	int					status;
	int					g_cost;
	int					h_cost;
	int					f_cost;
};

void					free_all(char **str);
void					free_textures(t_game *game);
void					*load_texture(void *mlx, char *path);
void					load_all_textures(t_game *game);
void					render_map(t_game *game);

char					**ft_split(char const *s, char c);
char					*get_word(char const *str, char c, int *index);
char					*read_map_file(char *file);
char					**split_map(char *map_str);

int						count_words(const char *str, char c);
int						close_game(t_game *game);
int						ft_strlen(char *str);
int						ft_tablen(char **str);
int						handle_input(int key, t_game *game);
int						is_valid_collec(char **s_game);
int						is_valid_content(char **s_game);
int						is_valid_exit(char **s_game);
int						is_valid_map(char **s_game);
int						is_valid_start(char **s_game);
int						is_valid_wall(char **s_game);
int						is_valid_width(char **s_game);

#endif