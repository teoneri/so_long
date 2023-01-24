/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:21:50 by mneri             #+#    #+#             */
/*   Updated: 2022/12/14 14:21:52 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_components(t_program *prg)
{
	if (prg->map.num_collectable < 1)
	{
		perror("Error\nInvalid map, missing collectable.");
		exit(0);
	}
	if (prg->map.num_player != 1)
	{
		perror("Error\nInvalid map, missing or more than one player.");
		exit(0);
	}
	if (prg->map.num_exit < 1)
	{
		perror("Error\nInvalid map, missing exit.");
		exit(0);
	}
}

void	ft_check_borders(char **map, t_program *prg)
{
	int	i;
	int	j;

	i = 0;
	while (i < prg->map.size.y)
	{
		if (map[i][0] != '1' || map[i][prg->map.size.x - 1] != '1')
		{
			perror("Error\nInvalid map, invalid border. \nError");
			exit(0);
		}
		i++;
	}
	j = 0;
	while (j < prg->map.size.x)
	{
		if (map[0][j] != '1' || map[prg->map.size.y - 1][j] != '1')
		{
			perror("Error\nInvalid map, invalid border. \nError");
			exit(0);
		}
		j++;
	}
}

void	ft_freematrix(char **map_copy, t_program *prg)
{
	int	i;

	i = 0;
	while (i < prg->map.size.y)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

int	ft_find_path(char **map_copy, t_program *prg, int i, int j)
{
	if (map_copy[i][j] == 'E')
		prg->err = 1;
	if (map_copy[i][j] == 'C')
		prg->clbl_ctr++;
	map_copy[i][j] = '1';
	if (map_copy[i + 1][j] != '1')
		ft_find_path(map_copy, prg, i + 1, j);
	if (map_copy[i - 1][j] != '1')
		ft_find_path(map_copy, prg, i - 1, j);
	if (map_copy[i][j + 1] != '1')
		ft_find_path(map_copy, prg, i, j + 1);
	if (map_copy[i][j - 1] != '1')
		ft_find_path(map_copy, prg, i, j - 1);
	return (0);
}
