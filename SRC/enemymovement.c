/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemymovement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:26:41 by mneri             #+#    #+#             */
/*   Updated: 2023/01/10 11:26:43 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_moveright(t_program *prg, int x, int y)
{
	if (prg->map.emx[y][x + 1] == '0')
	{
		prg->map.emx[y][x] = '0';
		prg->map.emx[y][x + 1] = 'Z';
		prg->map.enemy_pos.x++;
	}
	else if (prg->map.emx[y][x + 1] == 'P')
	{
		ft_printf("You Died  -  Game Over\n\n");
		ft_clean_exit(prg);
	}
}

void	ft_enemy_moveleft(t_program *prg, int x, int y)
{
	if (prg->map.emx[y][x - 1] == '0')
	{
		prg->map.emx[y][x] = '0';
		prg->map.emx[y][x - 1] = 'Z';
		prg->map.enemy_pos.x--;
	}
	else if (prg->map.emx[y][x - 1] == 'P')
	{
		ft_printf("You Died  -  Game Over\n\n");
		ft_clean_exit(prg);
	}
}

void	ft_enemy_movedown(t_program *prg, int x, int y)
{
	if (prg->map.emx[y - 1][x] == '0')
	{
		prg->map.emx[y][x] = '0';
		prg->map.emx[y - 1][x] = 'Z';
		prg->map.enemy_pos.y--;
	}
	else if (prg->map.emx[y - 1][x] == 'P')
	{
		ft_printf("You Died  -  Game Over\n\n");
		ft_clean_exit(prg);
	}
}

void	ft_enemy_moveup(t_program *prg, int x, int y)
{
	if (prg->map.emx[y + 1][x] == '0')
	{
		prg->map.emx[y][x] = '0';
		prg->map.emx[y + 1][x] = 'Z';
		prg->map.enemy_pos.y++;
	}
	else if (prg->map.emx[y + 1][x] == 'P')
	{
		ft_printf("You Died  -  Game Over\n\n");
		ft_clean_exit(prg);
	}
}
