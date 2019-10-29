/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:22:40 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/15 21:51:41 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_new_stack(char *haystack, char *replace, size_t a, size_t j)
{
	size_t	i;
	size_t	k;
	size_t	o;
	char	*newstack;

	i = ft_strlen(replace);
	k = ft_strlen(haystack);
	if (!(newstack = (char *)malloc(sizeof(char) * (k - j + i + 1))))
		return (NULL);
	o = a;
	ft_strncpy(newstack, haystack, a);
	while (i-- > 0)
		newstack[a++] = *replace++;
	while (k-- > 0)
		newstack[a++] = haystack[o + j++];
	return (newstack);
}

char			*ft_find_replace(char *haystack, char *find, char *replace)
{
	size_t	i;
	size_t	j;
	char	*p;
	size_t	h;

	i = 0;
	j = 0;
	h = ft_strlen(find);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == find[j])
		{
			if (find[j + 1] == '\0')
			{
				p = ft_new_stack(haystack, replace, i, h);
				return (p);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
