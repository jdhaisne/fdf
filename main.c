/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:00:53 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/02/13 14:58:44 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_tab(int **tab, t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < e->file_height)
	{
		while (j < e->file_width)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
	ft_putstr("file heigth = ");
	ft_putnbr(e->file_height);
	ft_putchar('\n');
	ft_putstr("file_width = ");
	ft_putnbr(e->file_width);
	ft_putchar('\n');
}

int		expose_hook(t_env *e)
{
	ft_putstr("expose heigth = ");
	ft_putnbr(e->win_height);
	ft_putstr("\n width = ");
	ft_putnbr(e->win_width);
	ft_putchar('\n');
	draw_file(e, e->tab);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	t_pos a;
	t_pos b;

	if (button == 1)
	{
		a.x = 0;
		a.y = 0;
		b.x = x;
		b.y = y;
		draw(e, &a, &b);
	}
	else if (button == 2)
	{
		a.x = e->win_height / 2;
		a.y = e->win_width / 2;
		b.x = x;
		b.y = y;
		draw(e, &a, &b);
	}
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		e->x_0 += 10;
	if (keycode == 125)
		e->y_0 += 10;
	if (keycode == 126)
		e->y_0 -= 10;
	if (keycode == 123)
		e->x_0 -= 10;
		ft_putendl("jd bg");
	if (keycode == 69)
		e->size += 0.2;
	if (keycode == 78)
		e->size -= 0.2;
	else
	{
		ft_putstr("keycode = ");
		ft_putnbr(keycode);
		ft_putchar('\n');
	}
		free_screen(e);
		draw_file(e, e->tab);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		e.mlx = mlx_init();
		read_file(av[1], &e);
		e.win_height = 900;
		e.win_width = 1600;
		get_x_y_0(&e);
		e.win = mlx_new_window(e.mlx, e.win_width, e.win_height, "bg");
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_key_hook(e.win, key_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_loop(e.mlx);
	}
	else
	{
		ft_putendl("error : no file");
	}
	return (0);
}
