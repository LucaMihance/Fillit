/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:16:03 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:05:27 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int j;
	int ok;

	i = 0;
	if (*str2 == '\0')
		return ((char*)str1);
	while (str1[i])
	{
		j = 0;
		ok = 1;
		while (str1[i + j] && str2[j] && ok)
		{
			if (str1[i + j] != str2[j])
				ok = 0;
			j++;
		}
		if (str1[i + j] == '\0' && str2[j] != '\0')
			ok = 0;
		if (ok)
			return ((char*)(str1 + i));
		i++;
	}
	return (NULL);
}
