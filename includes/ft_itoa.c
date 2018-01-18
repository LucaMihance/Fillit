/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:51:46 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:10:38 by lmihance         ###   ########.fr       */
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

char			*ft_itoa(int n)
{
	char			*tmp;
	char			*string;
	int				k;
	unsigned int	nb;

	if (!(tmp = ft_strnew(12)))
		return (NULL);
	tmp[0] = '0';
	k = -1;
	nb = (n < 0 ? -n : n);
	while (nb > 0)
	{
		tmp[++k] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		tmp[++k] = '-';
	if (!(string = ft_strrevcpy(tmp)))
		return (NULL);
	free(tmp);
	return (string);
}
