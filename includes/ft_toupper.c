/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:40:16 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:03:17 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}