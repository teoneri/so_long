/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:11:18 by mneri             #+#    #+#             */
/*   Updated: 2022/12/22 13:11:19 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_move_up(t_program *prg)
{
	int	x;
	int	y;

	x = prg->map.player_pos.x;
	y = prg->map.player_pos.y;
	if (prg->map.emx[y - 1][x] == 'E' && prg->collected == prg->clbl_ctr)
		ft_clean_exit(prg);
	if (prg->map.emx[y - 1][x] == '1' || prg->map.emx[y - 1][x] == 'E')
		return ;
	else if (prg->map.emx[y - 1][x] == 'C')
	{
		prg->map.player_pos.y--;
		prg->collected++;
		prg->move++;
	}
	else if (prg->map.emx[y - 1][x] == 'Z')
		ft_youdied(prg);
	else
	{
		prg->map.player_pos.y--;
		prg->move++;
	}
	prg->map.emx[y][x] = '0';
	prg->map.emx[y - 1][x] = 'P';
	ft_frame(prg);
}

void	ft_player_move_down(t_program *prg)
{
	int	x;
	int	y;

	x = prg->map.player_pos.x;
	y = prg->map.player_pos.y;
	if (prg->map.emx[y + 1][x] == 'E' && prg->collected == prg->clbl_ctr)
		ft_clean_exit(prg);
	else if (prg->map.emx[y + 1][x] == '1' || prg->map.emx[y + 1][x] == 'E')
		return ;
	else if (prg->map.emx[y + 1][x] == 'C')
	{
		prg->map.player_pos.y++;
		prg->collected++;
		prg->move++;
	}
	else if (prg->map.emx[y + 1][x] == 'Z')
		ft_youdied(prg);
	else
	{
		prg->map.player_pos.y++;
		prg->move++;
	}
	prg->map.emx[y][x] = '0';
	prg->map.emx[y + 1][x] = 'P';
	ft_frame(prg);
}

void	ft_player_move_left(t_program *prg)
{
	int	x;
	int	y;

	x = prg->map.player_pos.x;
	y = prg->map.player_pos.y;
	if (prg->map.emx[y][x - 1] == 'E' && prg->collected == prg->clbl_ctr)
		ft_clean_exit(prg);
	else if (prg->map.emx[y][x - 1] == '1' || prg->map.emx[y][x - 1] == 'E')
		return ;
	else if (prg->map.emx[y][x - 1] == 'C')
	{
		prg->map.player_pos.x--;
		prg->collected++;
		prg->move++;
	}
	else if (prg->map.emx[y][x - 1] == 'Z')
		ft_youdied(prg);
	else
	{
		prg->map.player_pos.x--;
		prg->move++;
	}
	prg->map.emx[y][x] = '0';
	prg->map.emx[y][x - 1] = 'P';
	ft_frame(prg);
}

void	ft_player_move_right(t_program *prg)
{
	int	x;
	int	y;

	x = prg->map.player_pos.x;
	y = prg->map.player_pos.y;
	if (prg->map.emx[y][x + 1] == 'E' && prg->collected == prg->clbl_ctr)
		ft_clean_exit(prg);
	else if (prg->map.emx[y][x + 1] == '1')
		return ;
	else if (prg->map.emx[y][x + 1] == 'C')
	{
		prg->map.player_pos.x++;
		prg->collected++;
		prg->move++;
	}
	else if (prg->map.emx[y][x + 1] == 'Z')
		ft_youdied(prg);
	else
	{
		prg->map.player_pos.x++;
		prg->move++;
	}
	prg->map.emx[y][x] = '0';
	prg->map.emx[y][x + 1] = 'P';
	ft_frame(prg);
}

void	ft_display_movement(t_program *prg)
{
	char	*movement;

	movement = ft_itoa(prg->move);
	mlx_string_put(prg->mx, prg->w, 32, 32, 0xFFFF00, movement);
	free(movement);
}
