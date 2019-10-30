/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <melhakki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:56:35 by ikadimi           #+#    #+#             */
/*   Updated: 2019/10/30 22:27:47 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_function2(t_init *start, int color)
{
	if (color == 2)
	{
		if ((start->b + 10) <= 255)
			start->b += 10;
		if ((start->g - 10) >= 0)
			start->g -= 10;
		if ((start->r - 10) >= 0)
			start->r -= 10;
	}
}

void	color_function(t_init *start, int color)
{
	if (color == 0)
	{
		if ((start->r + 10) <= 255)
			start->r += 10;
		if ((start->g - 10) >= 0)
			start->g -= 10;
		if ((start->b - 10) >= 0)
			start->b -= 10;
	}
	else if (color == 1)
	{
		if ((start->g + 10) <= 255)
			start->g += 10;
		if ((start->b - 10) >= 0)
			start->b -= 10;
		if ((start->r - 10) >= 0)
			start->r -= 10;
	}
	color_function2(start, color);
}

void	map_free(t_cord **map, t_init start)
{
	int i;

	i = 0;
	while (i < start.t.y)
		free(map[i++]);
	free(map);
	map = NULL;
}

void	key_press2(int button, t_init *start)
{
	create_pannel(*start);
	if (button == 53)
	{
		mlx_destroy_image(start->init, start->img);
		map_free(start->v, *start);
		map_free(start->tmp, *start);
		exit(0);
	}
	key_press3(button, start);
	if (button == 15)
		color_function(start, 0);
	else if (button == 5)
		color_function(start, 1);
	else if (button == 11)
		color_function(start, 2);
}

int		key_press(int button, t_init *start)
{
	mlx_clear_window(start->init, start->win);
	mlx_destroy_image(start->init, start->img);
	start->img = mlx_new_image(start->init, HEIGHT, WIDTH);
	key_press2(button, start);
	if (button == 34)
	{
		start->vangl = 0;
		start->hangl = 0;
		start->projetction = 1;
	}
	else if (button == 35)
	{
		start->vangl = 0;
		start->hangl = 0;
		start->projetction = 2;
	}
	map_free(start->tmp, *start);
	start->tmp = make_clone(*start);
	if (start->projetction == 1)
		projec_iso(start->tmp, start);
	if (start->projetction == 2)
		projec_parallel(start->tmp, start);
	drow(*start, start->tmp);
	mlx_put_image_to_window(start->init, start->win, start->img, 0, 0);
	return (1);
}
