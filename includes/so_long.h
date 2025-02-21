/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:43:11 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/21 12:57:52 by reeer-aa         ###   ########.fr       */
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
# define MOVE_UP 119
# define MOVE_DOWN 115
# define MOVE_LEFT 97
# define MOVE_RIGHT 100

typedef struct s_game	t_game;
typedef struct s_node	t_node;
typedef struct s_point	t_point;

typedef struct s_textures
{
	void				*wall;
	void				*player;
	void				*collectible;
	void				*exit;
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

struct					s_point
{
	int					x;
	int					y;
};

void					fill(char **tab, t_point size, t_point cur);
void					flood_fill(char **tab, t_point size, t_point begin);
void					free_all(char **str);
void					free_map_copy(char **map_copy, t_point map_size);
void					free_textures(t_game *game);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*load_texture(void *mlx, char *path);
void					load_all_textures(t_game *game);
void					new_player_position(t_game *game);
void					print_double_array(char **array);
void					render_map(t_game *game);

char					**copy_map(char **map, t_point map_size);
char					**ft_split(char const *s, char c);
char					*get_word(char const *str, char c, int *index);
char					*read_map_file(char *file);
char					**split_map(char *map_str);

int						check_remaining_elements(char **map_copy,
							t_point map_size);
int						count_collectibles(char **s_game);
int						count_words(const char *str, char c);
int						close_game(t_game *game);
int						ft_strlen(char *str);
int						ft_tablen(char **str);
int						handle_input(int key, t_game *game);
int						is_empty(t_game *game, t_point map_size, t_point pos);
int						is_map_playable(t_game *game, t_point map_size);
int						is_valid_collec(char **s_game);
int						is_valid_content(char **s_game);
int						is_valid_exit(char **s_game);
int						is_valid_map(char **s_game);
int						is_valid_start(char **s_game);
int						is_valid_wall(char **s_game);
int						is_valid_width(char **s_game);

t_point					find_player_position(t_game *game);

#endif