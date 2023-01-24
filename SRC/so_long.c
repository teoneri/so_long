/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:44:51 by mneri             #+#    #+#             */
/*   Updated: 2022/12/05 12:44:54 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int keycode, t_program *prg)
{
	if (keycode == XK_Escape)
		ft_clean_exit(prg);
	else if (keycode == XK_s)
		ft_player_move_down(prg);
	else if (keycode == XK_w)
		ft_player_move_up(prg);
	else if (keycode == XK_d)
		ft_player_move_right(prg);
	else if (keycode == XK_a)
		ft_player_move_left(prg);
	ft_display_movement(prg);
	return (0);
}

int	close_x(t_program *prg)
{
	ft_clean_exit(prg);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	prg;

	prg.map.basemtx = ft_open_map(argv[1]);
	if (argc != 2 || !prg.map.basemtx)
	{
		perror("Error\nCould not find map");
		return (0);
	}
	prg.mx = mlx_init();
	ft_valid_map(prg.map.basemtx, &prg);
	ft_initialize(&prg);
	ft_find_enemy_position(prg.map.emx, &prg);
	mlx_hook(prg.w, 2, 1L << 0, *ft_input, &prg);
	mlx_loop_hook(prg.mx, ft_update_map, &prg);
	mlx_hook(prg.w, 17, 0, close_x, &prg);
	mlx_loop(prg.mx);
}
