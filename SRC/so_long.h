/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:31:33 by mneri             #+#    #+#             */
/*   Updated: 2022/12/05 12:31:34 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include <X11/keysym.h>
# include <stddef.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_image
{
	void	*img;
	int		x;
	int		y;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_image;

typedef struct s_sprite
{
	void	*img[3];
	int		x;
	int		y;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_sprite;

typedef struct s_tiles
{
	t_image	w;
	t_image	e;
	t_image	f;
	t_image	c;
	t_image	p;
	t_image	z;
}	t_tiles;

typedef struct s_map
{
	t_vector	size;
	char		**basemtx;
	char		**emx;
	t_vector	player_pos;
	t_vector	enemy_pos;
	int			num_collectable;
	int			num_player;
	int			num_exit;
}	t_map;

typedef struct s_program
{
	void		*mx;
	void		*w;
	t_tiles		t;
	t_sprite	s;
	int			move;
	int			err;
	int			clbl_ctr;
	int			collected;
	t_image		image;
	t_map		map;
}	t_program;

char		**ft_open_map(char *argv);
int			ft_input(int keycode, t_program *param);
void		ft_valid_map(char **map, t_program *program);
void		ft_check_borders(char **map, t_program *program);
void		ft_check_mapchars(char **map, t_program *program);
void		ft_check_components(t_program *program);
int			ft_find_path(char **map_copy, t_program *program, int i, int j);
void		ft_freematrix(char **map_copy, t_program *project);
char		**ft_copy_map(char **map, t_program *program);
void		ft_render(t_program *prg, int i, int j, int f);
t_tiles		ft_get_images(t_program *program);
void		ft_player_move_up(t_program *program);
void		ft_player_move_down(t_program *program);
void		ft_player_move_left(t_program *program);
void		ft_player_move_right(t_program *program);
void		ft_clean_exit(t_program *program);
void		ft_display_movement(t_program *program);
void		ft_check_rectangle(char **map, t_program *prg);
void		ft_check_mapchars_part1(char c, int i, int j, t_program *prg);
int			ft_update_map(t_program *prg);
void		ft_enemy_moveup(t_program *prg, int x, int y);
void		ft_enemy_movedown(t_program *prg, int x, int y);
void		ft_enemy_moveleft(t_program *prg, int x, int y);
void		ft_enemy_moveright(t_program *prg, int x, int y);
void		ft_youdied(t_program *prg);
void		ft_find_enemy_position(char **em, t_program *prg);
void		ft_update_enemy_map(char **em, t_program *prg);
void		ft_initialize(t_program *prg);
t_sprite	ft_get_sprite(t_program *prg);
void		ft_frame(t_program *prg);
void		ft_frametwo(t_program *prg, int i, int j, int f);
#endif
