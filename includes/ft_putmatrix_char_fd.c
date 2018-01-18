/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix_char_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:40:55 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:14:10 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmatrix_char_fd(const char **matrix, int n, int fd)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putstr_fd(matrix[i], fd);
		i++;
	}
}
