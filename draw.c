/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 16:06:13 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/02/13 14:48:53 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_dx(t_env *e, t_pos *a, int dx, int dy)
{
	int cumul;
	int i;
	int xinc;
	int yinc;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	cumul = dx / 2;
	i = 1;
	while (i <= dx)
	{
		a->x = a->x + xinc;
		cumul = cumul + dy;
		if (cumul >= dx)
		{
			cumul = cumul - dx;
			a->y = a->y + yinc;
		}
		mlx_pixel_put(e->mlx, e->win, a->x, a->y, 0xFF00FF);
		i++;
	}
}

void	draw_dy(t_env *e, t_pos *a, int dx, int dy)
{
	int cumul;
	int i;
	int xinc;
	int yinc;

	xinc = (dx > 0) ? 1 : -1;
	yinc = (dy > 0) ? 1 : -1;
	dx = abs(dx);
	dy = abs(dy);
	i = 1;
	cumul = dy / 2;
	while (i <= dy)
	{
		a->y = a->y + yinc;
		cumul = cumul + dx;
		if (cumul >= dy)
		{
			cumul = cumul - dy;
			a->x = a->x + xinc;
		}
		mlx_pixel_put(e->mlx, e->win, a->x, a->y, 0xFF00FF);
		i++;
	}
}

void	draw(t_env *e, t_pos *a, t_pos *destination)
{
	int dx;
	int dy;

	a->x = (a->x * e->size) + e->x_0;
	a->y = (a->y * e->size) + e->y_0;
	destination->x = (destination->x * e->size) + e->x_0;
	destination->y = (destination->y * e->size) + e->y_0;
	dx = destination->x - a->x;
	dy = destination->y - a->y;
	mlx_pixel_put(e->mlx, e->win, a->x, a->y, 0xFF0000);
	if (abs(dx) > abs(dy))
		draw_dx(e, a, dx, dy);
	else
		draw_dy(e, a, dx, dy);
}
