/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:37:09 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:12:08 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	k;

	i = 0;
	k = (unsigned char)c;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
		if (((unsigned char *)dest)[i - 1] == k)
			return (&((unsigned char *)dest)[i]);
	}
	return (NULL);
}
