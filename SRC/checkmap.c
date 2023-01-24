/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:20:38 by mneri             #+#    #+#             */
/*   Updated: 2022/12/02 13:20:42 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_open_map(char *argv)
{
	int		fd;
	char	*stash;
	char	*temp;
	char	**map;
	int		readed;

	readed = 1;
	temp = ft_calloc(sizeof(char), 2);
	stash = ft_calloc(sizeof(char), 1);
	fd = open(argv, O_RDONLY);
	while (readed != 0)
	{
		readed = read(fd, temp, 1);
		stash = ft_strjoin(stash, temp);
	}
	map = ft_split(stash, '\n');
	free(stash);
	free(temp);
	close(fd);
	return (map);
}

void	ft_valid_map(char **map, t_program *prg)
{
	int		i;
	char	**map_copy;

	i = 0;
	prg->map.size.x = ft_strlen(map[i]);
	ft_check_rectangle(map, prg);
	prg->clbl_ctr = 0;
	ft_check_mapchars(map, prg);
	ft_check_borders(map, prg);
	ft_check_components(prg);
	map_copy = ft_copy_map(map, prg);
	ft_find_path(map_copy, prg, prg->map.player_pos.x, prg->map.player_pos.y);
	ft_freematrix(map_copy, prg);
	if (prg->err != 1 || prg->clbl_ctr != prg->map.num_collectable)
	{
		perror("Error\nUnable to find valid path to exit or collectable");
		exit(0);
	}
}

char	**ft_copy_map(char **map, t_program *prg)
{
	char	**map_copy;
	int		i;
	int		j;

	j = 0;
	i = 0;
	map_copy = ft_calloc(sizeof(char *), prg->map.size.y);
	while (i < prg->map.size.y)
	{
		map_copy[i] = ft_calloc(sizeof(char), prg->map.size.x + 1);
		i++;
	}
	i = 0;
	while (i < prg->map.size.y)
	{
		j = 0;
		while (j < prg->map.size.x + 1)
		{
			map_copy[i][j] = map[i][j];
			j++;
		}
		map_copy[i][j - 1] = '\0';
		i++;
	}
	return (map_copy);
}

void ft_clean_exit(t_program *prg)
{
    ft_printf("      ʕ •ᴥ•ʔ\nThanks for playing!\n      ʕ •ᴥ•ʔ\n");
    mlx_destroy_image(prg->mx, prg->t.e.img);
    mlx_destroy_image(prg->mx, prg->t.w.img);
    mlx_destroy_image(prg->mx, prg->s.img[0]);
    mlx_destroy_image(prg->mx, prg->s.img[1]);
    mlx_destroy_image(prg->mx, prg->s.img[2]);
    mlx_destroy_image(prg->mx, prg->t.c.img);
    mlx_destroy_image(prg->mx, prg->t.f.img);
    mlx_destroy_image(prg->mx, prg->t.z.img);
    mlx_destroy_window(prg->mx, prg->w);
    ft_freematrix(prg->map.basemtx, prg);
    ft_freematrix(prg->map.emx, prg);
    mlx_destroy_display(prg->mx);
    exit(0);
}

void	ft_initialize(t_program *prg)
{
	int	x;
	int	y;

	x = prg->map.size.x * 64;
	y = prg->map.size.y * 64;
	prg->w = mlx_new_window(prg->mx, x, y, "so_long");
	prg->t = ft_get_images(prg);
	prg->s = ft_get_sprite(prg);
	prg->map.emx = ft_copy_map(prg->map.basemtx, prg);
	prg->move = 0;
	prg->collected = 0;
}
