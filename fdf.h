/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <melhakki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:43:48 by ikadimi           #+#    #+#             */
/*   Updated: 2019/10/30 22:45:21 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# define HEIGHT 800
# define WIDTH 800
# define BUFFSIZE 5000

typedef struct		s_cord
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_cord;

typedef struct		s_norm
{
	int				i;
	int				j;
	t_cord			s;
	t_cord			f;
}					t_norm;

typedef struct		s_init
{
	void			*init;
	void			*img;
	void			*win;
	t_cord			t;
	int				att;
	int				r;
	int				g;
	int				b;
	unsigned char	*img_str;
	int				**map;
	t_cord			**tmp;
	t_cord			**v;
	t_cord			ini;
	int				mov;
	int				buff;
	double			vangl;
	double			hangl;
	int				projetction;
	char			*file;
}					t_init;

typedef struct		s_file
{
	int				ret;
	int				fd;
	char			*file;
}					t_file;

void				line_draw(t_cord pi, t_cord pf, t_init start);
char				*read_file(char **av);
char				*file_checker(char *file);
int					first_line_length(char *file);
t_cord				**map_alloc(t_init *start);
t_cord				tab_length(char *file);
void				tab_free(char **tab);
void				projec_parallel(t_cord **map, t_init *start);
void				projec_iso(t_cord **map, t_init *start);
void				init_prog(t_init *start);
int					key_press(int button, t_init *start);
t_cord				**make_clone(t_init t);
void				drow(t_init start, t_cord **map);
int					index_of(char *str, char c);
int					first_line_length(char *file);
void				create_pannel(t_init start);
void				key_press3(int button, t_init *start);

#endif
