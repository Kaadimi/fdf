#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int		index_of(char *str, char c)
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

int		color_converter(char *hex)
{
	char	str[16] = "0123456789ABCDEF";
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = 0;
	while (hex[i])
		i++;
	printf("this is hexa == %s this is length == %d\n", hex, i);
	while (i-- > 2)
	{
		printf("%c\n", hex[i]);
		tmp += (index_of(str, hex[i]) * pow(16, j));
		j++;
	}
	//printf("this is r == %d g == %d b == %d\n", (tmp / (256*256), (tmp / 256) % 256), tmp % 256);
	return (tmp - 1);
}

int main()
{
	printf("%f\n", pow(2, 0));
	char *str = ft_strdup("0xFFF");
	printf("this is color == %d\n", color_converter(str));
	return 0;
}
