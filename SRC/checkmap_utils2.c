/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:02:17 by mneri             #+#    #+#             */
/*   Updated: 2023/01/03 12:02:18 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_rectangle(char **map, t_program *prg)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (prg->map.size.x != (int)ft_strlen(map[i]))
		{
			perror("Error\nInvalid map size, non rectangular");
			exit(0);
		}
		i++;
	}
	prg->map.size.y = i;
}

void	ft_check_mapchars_part1(char c, int i, int j, t_program *prg)
{
	if (c == 'E')
	{
		prg->map.num_exit++;
	}
	else if (c == 'P')
	{
		prg->map.num_player++;
		prg->map.player_pos.x = j;
		prg->map.player_pos.y = i;
	}
	else if (c == 'C')
	{
		prg->map.num_collectable++;
	}
	else
	{
		perror("Error\nInvalid map, unauthorized character.");
		exit(0);
	}
}

void	ft_check_mapchars(char **map, t_program *prg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	prg->map.num_exit = 0;
	prg->map.num_player = 0;
	prg->map.num_collectable = 0;
	while (map[i] != 0)
	{
		while (j < prg->map.size.x - 1)
		{
			if (map[i][j] == '1')
				;
			else if (map[i][j] == '0' || map[i][j] == 'Z')
				;
			else
				ft_check_mapchars_part1(map[i][j], i, j, prg);
			j++;
		}
		j = 0;
		i++;
	}
}
