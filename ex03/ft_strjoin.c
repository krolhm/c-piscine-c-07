/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:38:34 by rbourgea          #+#    #+#             */
/*   Updated: 2019/09/11 12:17:42 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int		ft_total(int size, char **strs, char *sep)
{
	int	total;
	int	n;

	total = 0;
	n = 0;
	while (n < size)
	{
		total += ft_strlen(strs[n]);
		if (n + 1 < size)
			total += ft_strlen(sep);
		n++;
	}
	return (total);
}

char	*ft_malloc(int size, char **strs, char *sep)
{
	int		total;
	char	*str;

	if (size <= 0)
		return (NULL);
	total = ft_total(size, strs, sep);
	str = (char*)malloc(sizeof(char) * (total + 1));
	if (str == NULL)
		return (0);
	return (str);
}

char	*ft_sep(char *sep, char *str, int b, int n)
{
	b = 0;
	while (sep[b])
	{
		str[n] = sep[b];
		b++;
		n++;
	}
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		a;
	int		b;
	int		n;
	char	*str;

	a = -1;
	n = 0;
	if (size == 0)
		return ((char*)malloc(sizeof(char)));
	str = ft_malloc(size, strs, sep);
	while (strs[++a])
	{
		b = -1;
		while (strs[a][++b])
		{
			str[n] = strs[a][b];
			n++;
		}
		if (a == size - 1)
			break ;
		str = ft_sep(sep, str, b, n);
		n += ft_strlen(sep);
	}
	str[n] = '\0';
	return (str);
}
