/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <melhakki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:45:59 by ikadimi           #+#    #+#             */
/*   Updated: 2019/10/30 23:05:24 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		line_length_checker_2(char *file, int *i, int el, int *checker)
{
	if (file[*i] != ' ')
	{
		while (file[*i] != ' ')
		{
			if (file[*i] == '\0' || file[*i] == '\n')
				break ;
			*i += 1;
		}
		*checker += 1;
	}
	if (file[*i] == '\n' || file[*i] == '\0')
	{
		if (*checker < el)
		{
			ft_putstr("Found wrong line length. 1 Exiting.\n");
			return (0);
		}
		*checker = 0;
	}
	return (1);
}

int		line_length_checker(char *file)
{
	int i;
	int el;
	int checker;

	i = -1;
	checker = 0;
	el = first_line_length(file);
	while (file[++i] != '\0')
		if (!line_length_checker_2(file, &i, el, &checker))
			return (0);
	return (1);
}

char	*file_checker(char *file)
{
	int i;
	int wrong;

	wrong = 1;
	if (ft_strlen(file) <= 1)
	{
		ft_putstr("No data found.\n");
		return (NULL);
	}
	i = -1;
	while (file[++i])
	{
		if (file[i] == '\n' && file[i + 1] == '\n')
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			wrong = 0;
			break ;
		}
	}
	if (wrong == 1)
		wrong = line_length_checker(file);
	if (wrong == 1)
		return (file);
	else
		return (NULL);
}

int		file_length(char **av)
{
	char	buf[BUFFSIZE + 1];
	int		ret;
	int		fd;
	int		i;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if ((ret = read(fd, buf, BUFFSIZE)) == -1)
	{
		ft_putstr("File was open but not read\n");
		exit(0);
	}
	else
		i += ret;
	while ((ret = read(fd, buf, BUFFSIZE)))
		i += ret;
	return (i);
}

char	*read_file(char **av)
{
	char	buf[BUFFSIZE + 1];
	t_file	b;
	int		k;

	if ((b.fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("Something wrong with the File\n");
		exit(0);
	}
	k = file_length(av);
	if (!(b.file = ft_strnew(k)))
	{
		ft_putstr("Not enaugh space in device\n");
		exit(0);
	}
	while ((b.ret = read(b.fd, buf, BUFFSIZE)))
		ft_strcat(b.file, buf);
	b.file[k] = '\0';
	return (b.file);
}
