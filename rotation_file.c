/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:52:28 by ikadimi           #+#    #+#             */
/*   Updated: 2019/10/30 20:14:07 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_vertical(int *x, int *z, t_init start)
{
	int previous_x;
	int previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = previous_x * cos(start.vangl) + previous_z * sin(start.vangl);
	*z = -previous_x * sin(start.vangl) + previous_z * cos(start.vangl);
}

void	rotation_horizontal(int *y, int *z, t_init start)
{
	int previous_y;
	int previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = (previous_y * cos(start.hangl) - previous_z * sin(start.hangl));
	*z = previous_y * sin(start.hangl) + previous_z * cos(start.hangl);
}

void	iso(int *x, int *y, int z, int mov)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599) + mov;
	*y = -z + ((previous_x + previous_y) * sin(0.523599));
}

void	projec_iso(t_cord **map, t_init *start)
{
	int i;
	int j;

	i = 0;
	while (i < start->t.y)
	{
		j = 0;
		while (j < start->t.x)
		{
			iso(&map[i][j].x, &map[i][j].y,
					start->att * map[i][j].z, start->mov);
			j++;
		}
		i++;
	}
}

void	projec_parallel(t_cord **map, t_init *start)
{
	int i;
	int j;

	start->ini.x = 0;
	start->ini.y = 0;
	i = 0;
	while (i < start->t.y)
	{
		j = 0;
		while (j < start->t.x)
		{
			map[i][j].z = start->att * map[i][j].z;
			rotation_horizontal(&map[i][j].y, &map[i][j].z, *start);
			rotation_vertical(&map[i][j].x, &map[i][j].z, *start);
			j++;
		}
		i++;
	}
}
