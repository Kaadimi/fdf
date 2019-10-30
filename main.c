/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <melhakki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:24:55 by melhakki          #+#    #+#             */
/*   Updated: 2019/10/30 22:50:42 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_pannel(t_init start)
{
	mlx_string_put(start.init, start.win, (WIDTH +
				100), 50, 9856255, "PANNEL");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 80, 16777215, "<- Left  -> Right");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 110, 16777215, "Arrow up Increase Z");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 140, 16777215, "Arrow down Decrease Z");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 170, 16777215, "P For Parallel Projection");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 200, 16777215, "I For Isometric Projection");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 230, 16777215, "8 - 2 Vertical Rotation");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 260, 16777215, "4 - 6 Horizental Rotation");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 290, 16711680, "R To increase Red");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 320, 65280, "G To increase Green");
	mlx_string_put(start.init, start.win, (WIDTH +
				20), 350, 255, "B To increase Blue");
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
	start->img_str = (unsigned char *)mlx_get_data_addr(start->img,
			&b_p, &s_l, &endian);
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

void	drow2(t_init start, t_norm n, t_cord **map)
{
	n.s = map[n.i][n.j];
	n.s.x = n.s.x + (WIDTH / 2);
	n.s.y = n.s.y + (HEIGHT / 2);
	if (n.j + 1 < start.t.x)
	{
		n.f = map[n.i][n.j + 1];
		n.f.x = n.f.x + (WIDTH / 2);
		n.f.y = n.f.y + (HEIGHT / 2);
		line_draw(n.s, n.f, start);
	}
	if (n.i + 1 < start.t.y)
	{
		n.f = map[n.i + 1][n.j];
		n.f.x = n.f.x + (WIDTH / 2);
		n.f.y = n.f.y + (HEIGHT / 2);
		line_draw(n.s, n.f, start);
	}
}

void	drow(t_init start, t_cord **map)
{
	t_norm	n;

	n.i = 0;
	while (n.i < start.t.y)
	{
		n.j = 0;
		while (n.j < start.t.x)
		{
			drow2(start, n, map);
			n.j++;
		}
		n.i++;
	}
}

int		main(int ac, char **av)
{
	t_init	start;

	if (ac == 2)
	{
		if (!(start.file = file_checker(read_file(av))))
			return (0);
		init_prog(&start);
		projec_iso(start.tmp, &start);
		drow(start, start.tmp);
		mlx_put_image_to_window(start.init, start.win, start.img, 0, 0);
		mlx_hook(start.win, 2, 0, key_press, &start);
		mlx_loop(start.init);
	}
	else
		ft_putstr("Usage : ./fdf <filename>\n");
}
