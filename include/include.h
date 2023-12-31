/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muganiev <muganiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:53:50 by muganiev          #+#    #+#             */
/*   Updated: 2023/07/01 17:54:57 by muganiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../utils/get_next_line/get_next_line.h"
# include "../utils/libft/libft.h"

# define CUB 10

// Keycodes for mlx control character movement in the game
# define DESTROY 17
# define KEY_RELEASE 3
# define KEY_PRESS 2

// Keycodes for Mac
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define INT_MAX 2147483647

typedef struct s_parss
{
	char			**all;
	char			**map;

	char			*ceiling;
	char			*floor;

	char			*west;
	char			*east;
	char			*south;
	char			*north;

	int				w_index;
	int				e_index;
	int				s_index;
	int				n_index;

	int				c_index;
	int				f_index;

	int				map_index;
}					t_parss;

typedef struct s_valid_data
{
	unsigned int	ceiling[3];
	unsigned int	floor[3];
	char			*so;
	char			*no;
	char			*ea;
	char			*we;
	char			**maps;
	int				map_len;
	int				line_len;
	char			player;
}					t_valid_data;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				w_win;
	int				h_win;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_mlx;
typedef struct s_key
{
	int				x;
	int				y;
	int				pov;
}					t_key;

typedef struct s_texture
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}	t_texture;

typedef struct s_norm
{
	double			first_x;
	double			first_y;
	double			step_x;
	double			step_y;
	double			cub_distance;
	double			wall_height;
	int				start;
	int				end;
	unsigned int	color;
	t_texture		*choiceast_txt;
	double			start_angle;
}	t_norm;

typedef struct s_all
{
	t_parss			parss;
	t_valid_data	valid;
	t_mlx			mlx;
	t_key			key;
	unsigned int	len;
	int				x_p_pos;
	int				y_p_pos;
	double			x_player;
	double			y_player;
	double			direction_ang;
	double			rotation_speed;
	double			horizontal_distance;
	double			verticale_distance;
	double			ver_x;
	double			ver_y;
	double			hor_x;
	double			hor_y;
	double			x_offset;
	t_texture		west_txt;
	t_texture		east_txt;
	t_texture		north_t;
	t_texture		south_t;
	t_texture		minimap;
	t_norm			norm;
}					t_all;

// mlx_utils
void				init_mlx(t_all *data);
int					mlx_close(t_all *data);
int					mlx_keyrelease(int keycode, t_all *data);
int					mlx_key(int keycode, t_all *data);
int					mlx_keypress(t_all *data);
void				my_mlx_pixel_put(t_all *data, int x, int y, \
					unsigned int color);

// list of functions that are used to move the player around the map.
void				move_up(t_all *data);
void				move_down(t_all *data);
void				move_left(t_all *data);
void				move_right(t_all *data);
void				rotate_left_and_right(t_all *data, int direction);

// parsing
int					parsing(char *av, t_all *data);

// parsing utils
void				init_data(t_all *data);
int					validate_file_extension(char *av);
int					read_file(char *file, t_all *data, int i);

// free
void				free_metadata(t_all *data);
void				free_all(t_all *data);
void				free_rgb(char **rgb);
void				free_textures(t_all *data);
void				free_map(t_all *data);
void				free_parsing_data(t_all *data);
void				free_maps(t_all *data);

// get_textures
int					parse_west(t_all *data);
int					parse_east(t_all *data);
int					parse_south(t_all *data);
int					parse_north(t_all *data);

// get_colors
int					parse_floor(t_all *data);
int					parse_ceiling(t_all *data);

// get_all
int					get_info_of_map(t_all *data);
void				save_map(t_all *data, int i, int len, int temp);

// check colors
int					check_ceiling(t_all *data, int j);
int					validate_rgb_colors(t_all *data);

// validate_rgb_colors_utils
int					count_commas(char *str);
int					check_rgb_validity(char **rgb);
int					fill_ceiling_color(char **color, t_all *data);
int					fill_floor_color(char **color, t_all *data);

// validate_textures
int					validate_textures(t_all *data);

// validate_textures_utils
int					open_file(char *str);
void				init_textures(t_all *data);

// validate_map
int					check_is_white_spaces(char *str);
int					validate_map(t_all *data);
unsigned int		big_len(t_all *data);
void				init_map(t_all *data);
int					check_characters(t_all *data);
int					first_and_last_char(char **str, int map_len, int line_len);
int					search(char *src, char *str);
int					endmap_index(char **str);
void				add_space(t_all *data);
void				init_angle(t_all *data);
int					check_valid_map(t_all *data);
int					check_player(t_all *data, int i, int j, int player);
int					middle_char(t_all *data, int i, int j, int start);
int					middle_char_helper(t_all *data, int i, int j);
int					zero_checker(t_all *data, int i, int j);
int					check_space(t_all *data, int i, int j);
int					check_is_map_empty(char *str);
int					check_wall(t_all *data, double y, double x);
int					check_wall_y(t_all *data, int x_wall, int y_wall);
int					check_wall_x(t_all *data, int x_wall, int y_wall);

// drawing
int					start_game(t_all *data);
void				player_position(t_all *data, int x, int y, int *player);
double				normalize_angle(double ang);
double				calculate_distance(t_all *data, double y, double x);
int					is_left(double ang);
int					is_up(double ang);
unsigned int		get_textures(t_texture txt, double y, t_all *data, \
					double wal_h);
unsigned int		floor_color(t_all *data);
unsigned int		ceiling_color(t_all *data);

// intersection
void				horizontal_inter_helper(t_all *data, double ang, \
					int *index_x, int *index_y);
void				horizontal_inter_init(t_all *data, double ang);
void				horizontal_inter(t_all *data, double ang);
void				vertical_inter_init(t_all *data, double ang);
void				vertical_inter_helper(t_all *data, \
					double ang, int *index_y, int *index_x);
void				vertical_inter(t_all *data, double ang);

void				render_minimap(t_all *data);
void				draw_inside_circle(t_all *data, double y,
						double x, int color);
void				draw_miniplayer(t_all *data, double x, double y, int color);

#endif
