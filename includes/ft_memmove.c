/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:49:33 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:12:30 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*strd;
	char	*strs;
	size_t	i;

	strd = (char*)dest;
	strs = (char*)src;
	i = 0;
	if (strs < strd)
	{
		while ((int)(--n) >= 0)
			strd[n] = strs[n];
	}
	else
		while (i < n)
		{
			strd[i] = strs[i];
			i++;
		}
	return (dest);
}
