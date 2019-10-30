#include "fdf.h"

void drow(t_init start, t_cord **map)
{
    int i;
    int j;
    t_cord s;
    t_cord f;
    
    i = 0;
    while (i < start.t.y)
    {
        j = 0;
        while (j < start.t.x)
        {
            s = map[i][j];
			s.x = s.x + (WIDTH / 2);
			s.y = s.y + (HEIGHT / 2);
            if (j + 1 < start.t.x)
            {
                f = map[i][j + 1];
				f.x = f.x + (WIDTH / 2);
				f.y = f.y + (HEIGHT / 2);
                line_draw(s, f, start);
            }
            if (i + 1 < start.t.y)
            {
                f = map[i + 1][j];
				f.x = f.x + (WIDTH / 2);
				f.y = f.y + (HEIGHT / 2);
                line_draw(s, f, start);
            }
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
	t_init start;

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
