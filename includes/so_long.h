/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reeer-aa <reeer-aa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:43:11 by reeer-aa          #+#    #+#             */
/*   Updated: 2025/02/27 11:08:32 by reeer-aa         ###   ########.fr       */
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
# define BUFFER_SIZE 42
# define MOVE_UP 'w'
# define MOVE_DOWN 's'
# define MOVE_LEFT 'a'
# define MOVE_RIGHT 'd'
# define WALL_PATH "xpm/wall.xpm"
# define CHEST_PATH "xpm/chest.xpm"
# define EXIT_PATH "xpm/exit.xpm"
# define FLOOR_PATH "xpm/tile.xpm"
# define PLAYER_PATH "xpm/character_down_idle.xpm"
# define PLAYER_UP_PATH "xpm/character_up_move.xpm"
# define PLAYER_DOWN_PATH "xpm/character_down_move.xpm"
# define PLAYER_LEFT_PATH "xpm/character_left_move.xpm"
# define PLAYER_RIGHT_PATH "xpm/character_right_move.xpm"

typedef struct s_game	t_game;
typedef struct s_node	t_node;
typedef struct s_point	t_point;

struct					s_point
{
	int					x;
	int					y;
};

typedef struct s_textures
{
	void				*wall;
	void				*player;
	void				*player_right;
	void				*player_down;
	void				*player_up;
	void				*player_left;
	void				*collectible;
	void				*exit;
	void				*floor;
}						t_textures;

struct					s_game
{
	void				*mlx;
	void				*win;
	char				**map;
	int					player_x;
	int					player_y;
	int					collectibles;
	int					player_on_exit;
	int					moves;
	t_textures			textures;
	t_point				map_size;
};

void					destroy_all(t_game *game);
void					fill(char **tab, t_point size, t_point cur);
void					first_move(t_game *game);
void					flood_fill(char **tab, t_point size, t_point begin);
void					free_all(char **str);
void					free_map_copy(char **map_copy, t_point map_size);
void					free_textures(t_game *game);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					if_collec(t_game *game, t_point *pos);
void					if_exit(t_game *game, t_point *pos);
void					init_player_position(t_game *game);
void					init_size(t_game *game);
void					*load_texture(void *mlx, char *path);
void					move_up(t_game *game);
void					move_down(t_game *game);
void					move_left(t_game *game);
void					move_right(t_game *game);
void					new_player_position(t_game *game, t_point pos);
void					print_double_array(char **array);
void					rendering(t_game *game, int x, int y);
void					rendering_up(t_game *game, int x, int y);
void					rendering_down(t_game *game, int x, int y);
void					rendering_left(t_game *game, int x, int y);
void					rendering_right(t_game *game, int x, int y);
void					render_map(t_game *game);
void					render_map_up(t_game *game);
void					render_map_down(t_game *game);
void					render_map_left(t_game *game);
void					render_map_right(t_game *game);
void					update_player_position(t_game *game, t_point pos,
							char c);

char					**copy_map(char **map, t_point map_size);
char					**ft_split(char const *s, char c);
char					*ft_strchr(char *s, int c);
char					*ft_free(char *str);
char					*ft_strdup(char *s);
char					*ft_strjoin(char *s1, char *s2);
char					*get_next_line(int fd);
char					*get_word(char const *str, char c, int *index);
char					*part_line(char *str);
char					*read_map_file(char *file);
char					*read_line(int fd, char *this_line);
char					*save_remaining(char *str);
char					**split_map(char *map_str);

int						check_file_extension(char *filename);
int						check_remaining_elements(char **map_copy,
							t_point map_size);
int						close_game(t_game *game);
int						count_collectibles(char **s_game);
int						count_words(const char *str, char c);
int						ft_case(char c, va_list args);
int						ft_putchar(char c);
void					ft_putchar_final(char t[], int point, int nb);
int						ft_putchar_zero(int nb);
int						ft_putnbr(int n);
int						ft_putstr(char *s);
int						ft_printf(const char *str, ...);
int						ft_printhex(unsigned long long n, int maj);
int						ft_printptr(unsigned long long p);
int						ft_uputnbr(unsigned int n);
int						ft_strcmp(char *s1, char *s2);
int						ft_strlen(char *str);
int						ft_tablen(char **str);
int						gamemlx(t_game *game, char *map, char *argv[]);
int						handle_input(int key, t_game *game);
int						is_empty(t_game *game, t_point *pos);
int						is_map_playable(t_game *game);
int						is_valid_collec(char **s_game);
int						is_valid_content(char **s_game);
int						is_valid_exit(char **s_game);
int						is_valid_map(char **s_game);
int						is_valid_start(char **s_game);
int						is_valid_wall(char **s_game);
int						is_valid_width(char **s_game);
int						load_all_textures(t_game *game);

t_point					find_exit_position(t_game *game);
t_point					find_player_position(t_game *game);

#endif