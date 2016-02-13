/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:06:13 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/02/13 15:01:45 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	make_3d(int x, int y, int z, t_env *e)
{
	t_pos	a;
	int		res_x;
	int		res_y;

	res_x = (e->win_width / (e->file_width + 1));
	res_y = (e->win_height / (e->file_height + 1));
	a.x = ((0.72) * (x - y)) * res_x;
	a.y = (((-0.42 * (x + y)) + (0.98 * z)) * res_y);
	return (a);
}

void	get_x_y_0(t_env *e)
{
	int diag;
	int res_x;
	int res_y;

	res_x = (e->win_width / (e->file_width + 1));
	res_y = (e->win_height / (e->file_height + 1));
	diag = sqrt(pow(e->file_width * res_x, 2) + pow(e->file_height * res_y, 2));
	e->x_0 = e->win_width / 2;
	e->y_0 = e->win_height / 4;
	e->size = 1;
	while (diag > e->win_width || diag > e->win_height)
	{
		ft_putendl("a");
		e->size = e->size / 2;
		diag = diag / 2;
	}
	ft_putnbr(e->size);
}

void	free_screen(t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < e->win_height)
	{
		while (x < e->win_width)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_file(t_env *e, t_pos **tab)
{
	t_pos i;
	t_pos a;
	t_pos b;

	i.y = 0;
	while (i.y < e->file_height)
	{
		i.x = 0;
		while (i.x < e->file_width)
		{
			a = tab[i.y][i.x];
			if (i.x > 0)
			{
				b = tab[i.y][i.x - 1];
				draw(e, &b, &a);
			}
			if (i.y > 0)
			{
				b = tab[i.y - 1][i.x];
				draw(e, &b, &a);
			}
			i.x++;
		}
		i.y++;
	}
}
