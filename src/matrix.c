/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 16:11:07 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/29 19:30:43 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tetrix_matrix_new(char **matrix, int size)
{
	int i;
	int j;

	i = 0;
	if (!(matrix = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(matrix[i] = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		j = 0;
		while (j < size)
		{
			matrix[i][j] = '.';
			j++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	matrix[i] = 0;
	return (matrix);
}

char	**rm_tetrix(char **matrix, t_tetrix *tet, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (matrix[i][j] == tet->c)
				matrix[i][j] = '.';
			j++;
		}
		i++;
	}
	return (matrix);
}

char	**ad_tetrix(char **matrix, t_tetrix *tet, int size)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tet->y[k] == i && tet->x[k] == j)
			{
				matrix[i][j] = tet->c;
				k++;
			}
			j++;
		}
		i++;
	}
	return (matrix);
}
