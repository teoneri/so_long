/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendermap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:32:16 by mneri             #+#    #+#             */
/*   Updated: 2022/12/22 11:32:18 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_tiles	ft_get_images(t_program *prg)
{
	t_tiles	t;

	t.w.img = mlx_xpm_file_to_image(prg->mx, "textures/1.xpm", &t.w.x, &t.w.x);
	t.f.img = mlx_xpm_file_to_image(prg->mx, "textures/0.xpm", &t.f.x, &t.f.y);
	t.c.img = mlx_xpm_file_to_image(prg->mx, "textures/C.xpm", &t.c.x, &t.c.y);
	t.e.img = mlx_xpm_file_to_image(prg->mx, "textures/E.xpm", &t.e.x, &t.e.y);
	t.z.img = mlx_xpm_file_to_image(prg->mx, "textures/Z.xpm", &t.z.x, &t.z.y);
	return (t);
}

t_sprite	ft_get_sprite(t_program *prg)
{
	t_sprite	s;

	s.img[0] = mlx_xpm_file_to_image(prg->mx, "textures/P.xpm", &s.x, &s.y);
	s.img[1] = mlx_xpm_file_to_image(prg->mx, "textures/P1.xpm", &s.x, &s.y);
	s.img[2] = mlx_xpm_file_to_image(prg->mx, "textures/P2.xpm", &s.x, &s.y);
	return (s);
}

void	ft_frame(t_program *prg)
{
	static int	counter;
	int			f;
	int			i;
	int			j;

	f = 0;
	i = 0;
	j = 0;
	counter++;
	if (counter == 8)
	{
		counter = 0;
		f++;
	}
	if (f >= 2)
		f = 0;
	while (i < prg->map.size.y)
	{
		ft_frametwo(prg, i, j, f);
		j = 0;
		i++;
	}
}

void	ft_frametwo(t_program *prg, int i, int j, int f)
{
	while (j <= prg->map.size.x - 1)
	{
		ft_render(prg, i, j, f);
		j++;
	}
}

void	ft_render(t_program *prg, int i, int j, int f)
{
	if (prg->map.emx[i][j] == '1')
		mlx_put_image_to_window(prg->mx, prg->w, prg->t.w.img, j * 64, i * 64);
	if (prg->map.emx[i][j] == '0')
		mlx_put_image_to_window(prg->mx, prg->w, prg->t.f.img, j * 64, i * 64);
	if (prg->map.emx[i][j] == 'E')
		mlx_put_image_to_window(prg->mx, prg->w, prg->t.e.img, j * 64, i * 64);
	if (prg->map.emx[i][j] == 'P')
		mlx_put_image_to_window(prg->mx, prg->w, prg->s.img[f], j * 64, i * 64);
	if (prg->map.emx[i][j] == 'C')
		mlx_put_image_to_window(prg->mx, prg->w, prg->t.c.img, j * 64, i * 64);
	if (prg->map.emx[i][j] == 'Z')
		mlx_put_image_to_window(prg->mx, prg->w, prg->t.z.img, j * 64, i * 64);
}
