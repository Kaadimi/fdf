/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:59:21 by ikadimi           #+#    #+#             */
/*   Updated: 2019/10/30 22:31:23 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			first_line_length(char *file)
{
	int el;
	int i;

	i = 0;
	el = 0;
	while (file[i] != '\0' && file[i] != '\n')
	{
		if (file[i] != ' ')
		{
			while (file[i] != ' ')
			{
				if (file[i] == '\0' || file[i] == '\n')
					return (el + 1);
				i += 1;
			}
			el++;
		}
		i += 1;
	}
	return (el);
}

int			index_of(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_cord		tab_length(char *file)
{
	t_cord	t;
	int		i;

	i = 0;
	t.x = first_line_length(file);
	t.y = 0;
	while (file[i])
	{
		if (file[i] == '\n')
			t.y++;
		i++;
	}
	return (t);
}

void		tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

t_cord		**make_clone(t_init t)
{
	int		i;
	int		j;
	t_cord	**map;

	i = 0;
	map = (t_cord **)malloc(sizeof(t_cord*) * t.t.y);
	while (i < t.t.y)
		map[i++] = (t_cord *)malloc(sizeof(t_cord) * t.t.x);
	map[0][0].x = t.ini.x;
	map[0][0].y = t.ini.y;
	i = 0;
	while (i < t.t.y)
	{
		j = 0;
		while (j < t.t.x)
		{
			map[i][j].x = t.v[i][j].x;
			map[i][j].y = t.v[i][j].y;
			map[i][j].z = t.v[i][j].z;
			map[i][j].color = t.v[i][j].color;
			j++;
		}
		i++;
	}
	return (map);
}
