/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:15:41 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:10:22 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *str, char c)
{
	size_t	size;

	size = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str && *str != c)
			size++;
		while (*str != c && *str)
			str++;
	}
	return (size);
}

static char		*ft_split(const char *str, char c)
{
	char	*a;
	int		k;
	size_t	size;

	k = -1;
	size = 0;
	while (*str && *str != c)
	{
		str++;
		size++;
	}
	str -= size;
	if (!(a = ft_strnew(size)))
		return (NULL);
	while (*str && *str != c)
		a[++k] = *str++;
	return (a);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**a;
	int		k;

	k = -1;
	if (!(a = (char **)malloc(sizeof(char *) * (ft_count(str, c) + 1))))
		return (NULL);
	while (str && *str)
	{
		while (*str == c)
			str++;
		if (*str)
			if (!(a[++k] = ft_split(str, c)))
				return (NULL);
		while (*str && *str != c)
			++str;
	}
	a[++k] = NULL;
	return (a);
}
