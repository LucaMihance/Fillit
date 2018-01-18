/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:09:44 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:07:02 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (!*s2)
		return ((char*)(s1));
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] && s2[j] && i + j < n && s1[i + j] == s2[j])
			j++;
		if (ft_strlen(s2) == j)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
