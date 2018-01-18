/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:50:30 by lmihance          #+#    #+#             */
/*   Updated: 2018/01/03 17:30:59 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tetx(t_tetrix **tet, int x, int y)
{
	int px;
	int py;
	int i;

	i = 0;
	px = 100;
	py = 100;
	while (i < 4)
	{
		if ((*tet)->x[i] < px)
			px = (*tet)->x[i];
		if ((*tet)->y[i] < py)
			py = (*tet)->y[i];
		i++;
	}
	i--;
	while (i >= 0)
	{
		(*tet)->x[i] = (*tet)->x[i] - px + x;
		(*tet)->y[i] = (*tet)->y[i] - py + y;
		i--;
	}
}

char	**ss(char **tmatrix, t_tetrix *tet, int size)
{
	int		i;
	int		j;
	char	**matrix;

	if (tet->next == NULL)
		return (tmatrix);
	matrix = NULL;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tetx(&tet, j, i);
			if (check_piece(tmatrix, tet, size))
				matrix = ss(ad_tetrix(tmatrix, tet, size),
						tet->next, size);
			if (matrix)
				return (matrix);
			tmatrix = rm_tetrix(tmatrix, tet, size);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	solve(t_tetrix *tet)
{
	char	**result;
	char	**tmatrix;
	int		size;

	size = 2;
	tmatrix = NULL;
	tmatrix = tetrix_matrix_new(tmatrix, size);
	result = NULL;
	while (!(result = ss(tmatrix, tet, size)))
	{
		size++;
		ft_memdel((void **)tmatrix);
		tmatrix = tetrix_matrix_new(tmatrix, size);
	}
	if (result != NULL)
		ft_putmatrix_char(result, size);
}
