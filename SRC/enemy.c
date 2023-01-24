/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:37:02 by mneri             #+#    #+#             */
/*   Updated: 2023/01/09 12:37:03 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_enemy_position(char **em, t_program *prg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < prg->map.size.y)
	{
		while (x < prg->map.size.x)
		{
			if (em[y][x] == '0' && em[y][x - 1] == '0')
			{
				if (em[y + 1][x] == '0' && em[y][x + 1] == '0')
				{
					prg->map.enemy_pos.x = x;
					prg->map.enemy_pos.y = y;
					return ;
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
	ft_update_enemy_map(em, prg);
}

void	ft_update_enemy_map(char **em, t_program *prg)
{
	em[prg->map.enemy_pos.y][prg->map.enemy_pos.x] = 'Z';
}

int	ft_update_map(t_program *prg)
{
	int	random;

	random = rand() % 4 + 1;
	usleep(100000);
	if (random == 1)
		ft_enemy_moveup(prg, prg->map.enemy_pos.x, prg->map.enemy_pos.y);
	else if (random == 2)
		ft_enemy_movedown(prg, prg->map.enemy_pos.x, prg->map.enemy_pos.y);
	else if (random == 3)
		ft_enemy_moveleft(prg, prg->map.enemy_pos.x, prg->map.enemy_pos.y);
	else if (random == 4)
		ft_enemy_moveright(prg, prg->map.enemy_pos.x, prg->map.enemy_pos.y);
	ft_frame(prg);
	ft_display_movement(prg);
	return (0);
}

void	ft_youdied(t_program *prg)
{
	ft_printf("You Died  -  Game Over\n\n");
	ft_clean_exit(prg);
}
