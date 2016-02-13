/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhaisne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:57:11 by jdhaisne          #+#    #+#             */
/*   Updated: 2016/02/13 14:27:24 by jdhaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void static	get_file_size(t_list *start, t_env *e)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = start->content;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
			j++;
		while (ft_isdigit(line[i]) || line[i] == '-')
			i++;
		while (line[i] == ' ')
			i++;
	}
	ft_putendl("A");
	i = 0;
	while (start)
	{
		start = start->next;
		i++;
	}
	e->file_width = j;
	e->file_height = i;
}

int static	**create_tab(t_list *start, t_env *e)
{
	int		i;
	int		j;
	char	*line;
	int		**tab;

	i = 0;
	tab = (int **)ft_memalloc(sizeof(int *) * e->file_height);
	while (i < e->file_height)
	{
		j = 0;
		line = start->content;
		tab[i] = (int *)ft_memalloc(sizeof(int) * e->file_width);
		while (j < e->file_width)
		{
			tab[i][j] = ft_atoi(line);
			while ((line[0] <= '9' && line[0] >= '0') || line[0] == '-')
				line++;
			while (line[0] == ' ')
				line++;
			j++;
		}
		start = start->next;
		i++;
	}
	return (tab);
}

t_pos		**calculate_pos(int **tab, t_env *e)
{
	t_pos **tab_pos;
	int x;
	int y;

	x = 0;
	y = 0;
	tab_pos = (t_pos **)ft_memalloc(sizeof(t_pos *) * e->file_height);
	while (x < e->file_height)
	{
		tab_pos[x] = (t_pos *)ft_memalloc(sizeof(t_pos) * e->file_width);
		x++;
	}
	while (y < e->file_height)
	{
		x= 0;
			while (x < e->file_width)
		{
			tab_pos[y][x] = make_3d(x, y, tab[y][x], e);
			x++;
		}
		y++;
	}
	return (tab_pos);
}

void		read_file(char *file, t_env *e)
{
	int		fd;
	int		**tab;
	char	*line;
	t_list	*start;
	t_list	*tmp;

	fd = open(file, O_RDONLY);
	line = NULL;
	get_next_line(fd, &line);
	start = ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1);
	tmp = start;
	free(line);
	while (get_next_line(fd, &line))
	{
		tmp->next = ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1);
		tmp = tmp->next;
		free(line);
	}
	get_file_size(start, e);
	tab = create_tab(start, e);
	e->tab = calculate_pos(tab, e);
}
