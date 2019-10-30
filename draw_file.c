/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <melhakki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:43:45 by ikadimi           #+#    #+#             */
/*   Updated: 2019/10/30 22:32:53 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_light_pixel(t_init start, int x, int y, int color)
{
	int i;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	i = x * 4 + WIDTH * 4 * y;
	if (color > -1)
	{
		start.img_str[i] = color % 256;
		start.img_str[i + 1] = ((color / 256) % 256);
		start.img_str[i + 2] = (color / (256 * 256));
	}
	else
	{
		start.img_str[i] = start.b;
		start.img_str[i + 1] = start.g;
		start.img_str[i + 2] = start.r;
	}
}

void	slop_high(t_cord pi, t_cord pf, t_init start)
{
	int dx;
	int dy;
	int xi;
	int pxx;

	dx = abs(pf.x - pi.x);
	dy = pf.y - pi.y;
	xi = (pf.x - pi.x >= 0) ? 1 : -1;
	pxx = 2 * dx - dy;
	while (pi.y <= pf.y)
	{
		ft_light_pixel(start, pi.x, pi.y, pi.color);
		if (pxx > 0)
		{
			pi.x += xi;
			pxx = pxx - (2 * dy);
		}
		pxx = pxx + (2 * dx);
		pi.y++;
	}
}

void	slop_low(t_cord pi, t_cord pf, t_init start)
{
	int dx;
	int dy;
	int yi;
	int pxx;

	dy = abs(pf.y - pi.y);
	dx = pf.x - pi.x;
	yi = (pf.y - pi.y >= 0) ? 1 : -1;
	pxx = 2 * dy - dx;
	while (pi.x <= pf.x)
	{
		ft_light_pixel(start, pi.x, pi.y, pi.color);
		if (pxx >= 0)
		{
			pi.y += yi;
			pxx = pxx - (2 * dx);
		}
		pxx = pxx + (2 * dy);
		pi.x++;
	}
}

void	line_draw(t_cord pi, t_cord pf, t_init start)
{
	if (abs(pf.y - pi.y) < abs(pf.x - pi.x))
	{
		if (pi.x > pf.x)
			slop_low(pf, pi, start);
		else
			slop_low(pi, pf, start);
	}
	else
	{
		if (pi.y > pf.y)
			slop_high(pf, pi, start);
		else
			slop_high(pi, pf, start);
	}
}

void	key_press3(int button, t_init *start)
{
	if (button == 126)
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
}
