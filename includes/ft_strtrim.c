/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:13:43 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:10:10 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strrevcpy(const char *const s)
{
	char	*start;
	char	*string;
	size_t	len;

	len = ft_strlen(s);
	if (!(string = ft_strnew(len)))
		return (NULL);
	start = string;
	while (len > 0)
		*string++ = s[--len];
	*string = '\0';
	return (start);
}

static size_t	value_to_trim(const char *s1, const char *s2)
{
	size_t	trim;
	size_t	len;

	trim = 0;
	len = ft_strlen(s1);
	while (*s1 == ' ' || *s1 == '\t' || *s1 == '\n')
	{
		++trim;
		++s1;
	}
	while (*s2 == ' ' || *s2 == '\t' || *s2 == '\n')
	{
		++trim;
		++s2;
	}
	return (trim == len * 2 ? len : trim);
}

char			*ft_strtrim(const char *s)
{
	char	*rev;
	char	*trim;
	int		k;
	size_t	len;

	if (!s)
		return (NULL);
	if (!(rev = ft_strrevcpy(s)))
		return (NULL);
	k = -1;
	len = ft_strlen(s) - value_to_trim(s, rev);
	ft_strclr(rev);
	if (!(trim = ft_strnew(len)))
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		++s;
	while (len--)
	{
		*(trim + ++k) = *s;
		++s;
	}
	return (trim);
}
