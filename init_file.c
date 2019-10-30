/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:56:35 by ikadimi           #+#    #+#             */
/*   Updated: 2019/10/30 15:59:12 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	else if (color == 2)
	{
		if ((start->b + 10) <= 255)
			start->b += 10;
		if ((start->g - 10) >= 0)
			start->g -= 10;
		if ((start->r - 10) >= 0)
			start->r -= 10;
	}
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
	if (button == 53)
	{
		mlx_destroy_image(start->init, start->img);
		map_free(start->v, *start);
		map_free(start->tmp, *start);
		exit(0);
	}
	else if (button == 126)
		start->att += 1;
	else if (button == 125)
		start->att -= 1;
	else if (button == 124)
		start->mov += 10;
	else if (button == 123)
		start->mov -= 10;
	else if (button == 91)
		start->hangl -= 0.1;
	else if (button == 84)
		start->hangl += 0.1;
	else if (button == 86)
		start->vangl -= 0.1;
	else if (button == 88)
		start->vangl += 0.1;
	else if (button == 15)
		color_function(start, 0);
	else if (button == 5)
		color_function(start, 1);
	else if (button == 11)
		color_function(start, 2);
}

void	create_pannel(t_init start)
{
	mlx_string_put(start.init, start.win, (WIDTH + 100), 50, 9856255, "PANNEL");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 80, 16777215, "<- Left  -> Right");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 110, 16777215, "Arrow up Increase Z");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 140, 16777215, "Arrow down Decrease Z");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 170, 16777215, "P For Parallel Projection");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 200, 16777215, "I For Isometric Projection");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 230, 16777215, "8 - 2 Vertical Rotation");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 260, 16777215, "4 - 6 Horizental Rotation");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 290, 16711680, "R To increase Red");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 320, 65280, "G To increase Green");
	mlx_string_put(start.init, start.win, (WIDTH + 20), 350, 255, "B To increase Blue");
}

int key_press(int button, t_init *start)
{
	mlx_clear_window(start->init, start->win);
	mlx_destroy_image(start->init, start->img);
	start->img = mlx_new_image(start->init, HEIGHT, WIDTH);
	create_pannel(*start);
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
	printf("this is button == %d\n", button);
	return 1;
}

void	init_prog(t_init *start)
{
	int b_p;
	int s_l;
	int endian;

	start->init = mlx_init();
	start->win = mlx_new_window(start->init, (HEIGHT + 300), WIDTH, "fdf");
	create_pannel(*start);
	start->img = mlx_new_image(start->init, HEIGHT, WIDTH);
	start->img_str = (unsigned char *)mlx_get_data_addr(start->img, &b_p, &s_l, &endian);
	start->ini.x = 0;
	start->ini.y = 0;
	start->hangl = 0;
	start->hangl = 0;
	start->r = 255;
	start->g = 0;
	start->b = 255;
	start->att = 1;
	start->mov = 0;
	start->v = map_alloc(start);
	start->tmp = make_clone(*start);
	start->projetction = 1;
}
