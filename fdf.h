/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:01:34 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/02/13 14:35:58 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			file_height;
	int			file_width;
	int			win_height;
	int			win_width;
	t_pos		**tab;
	int			x_0;
	int			y_0;
	float			size;
}				t_env;

void			read_file(char *file, t_env *e);
void			draw(t_env *e, t_pos *a, t_pos *destination);
void			draw_file(t_env *e, t_pos **tab);
t_pos			make_3d(int x, int y, int z, t_env *e);
void			get_x_y_0(t_env *e);
void			free_screen(t_env *e);

#endif
