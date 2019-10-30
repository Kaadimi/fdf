/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:50:09 by ikadimi           #+#    #+#             */
/*   Updated: 2019/10/30 22:46:07 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			find_the_coma(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != ',')
		i++;
	return (i);
}

int			color_converter(char *hex)
{
	char	*str;
	int		tmp;
	int		i;
	int		j;

	str = "0123456789ABCDEF";
	i = 0;
	j = 0;
	tmp = 0;
	while (hex[i])
		i++;
	while (i-- > 2)
	{
		tmp += (index_of(str, hex[i]) * pow(16, j));
		j++;
	}
	return (tmp - 1);
}

void		map_alloc_3(char **str, int i, int j, t_cord **map)
{
	if (ft_strstr(str[j], ","))
	{
		map[i][j].color = color_converter(str[j] + find_the_coma(str[j]) + 1);
		str[j][find_the_coma(str[j])] = '\0';
		map[i][j].z = ft_atoi(str[j]);
	}
	else
	{
		map[i][j].z = ft_atoi(str[j]);
		map[i][j].color = -1;
	}
}

void		map_alloc_2(char **tab, int i, t_cord **map, t_init *start)
{
	int		j;
	char	**str;
	int		o;
	int		k;

	str = ft_strsplit(tab[i], ' ');
	j = 0;
	if (i == 0)
		o = 0;
	k = 0;
	while (j < start->t.x)
	{
		if (i != 0 || j != 0)
		{
			map[i][j].x = k - (start->t.x * start->buff / 2);
			map[i][j].y = o - (start->t.y * start->buff / 2);
		}
		map_alloc_3(str, i, j, map);
		k += start->buff;
		j++;
	}
	o += start->buff;
	tab_free(str);
}

t_cord		**map_alloc(t_init *start)
{
	char	**tab;
	int		i;
	t_cord	**map;

	i = 0;
	tab = ft_strsplit(start->file, '\n');
	start->t = tab_length(start->file);
	free(start->file);
	map = (t_cord **)malloc(sizeof(t_cord*) * start->t.y);
	while (i < start->t.y)
		map[i++] = (t_cord *)malloc(sizeof(t_cord) * start->t.x);
	start->buff = (WIDTH / (start->t.x * 1.5));
	map[0][0].x = -(start->t.x * start->buff / 2);
	map[0][0].y = -(start->t.y * start->buff / 2);
	i = 0;
	while (i < start->t.y)
		map_alloc_2(tab, i++, map, start);
	tab_free(tab);
	return (map);
}
