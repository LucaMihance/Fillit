/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:02:10 by lmihance          #+#    #+#             */
/*   Updated: 2018/01/09 15:03:57 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_links(char *str, int j)
{
	int k;
	int i;

	i = 0;
	k = 0;
	while (i + j < 20 + j)
	{
		if (str[i + j] == '#')
		{
			if ((i + j + 1 < 20 + j) && str[i + j + 1] == '#')
				k++;
			if ((i + j - 1 >= 0 + j) && str[i + j - 1] == '#')
				k++;
			if ((i + j + 5 < 20 + j) && str[i + j + 5] == '#')
				k++;
			if ((i + j - 5 >= 0 + j) && str[i + j - 5] == '#')
				k++;
		}
		i++;
	}
	if (k == 6 || k == 8)
		return (1);
	return (0);
}

int		check_char_nbr(char *str, int j)
{
	int	i;
	int	dots;
	int	hash;
	int	newline;

	i = 0;
	dots = 0;
	hash = 0;
	newline = 0;
	while (i + j < 20 + j && str[i + j] != '\0')
	{
		if (str[i + j] == '.')
			dots++;
		if (str[i + j] == '#')
			hash++;
		if (str[i + j] == '\n')
			newline++;
		i++;
	}
	if (dots == 12 && hash == 4 && newline == 4)
		return (1);
	return (0);
}

int		check_str(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i + j] != '\0')
	{
		if (!(check_links(str, j) && check_char_nbr(str, j)))
			return (0);
		i = 19;
		if (str[i + j] == '\n' && str[i + j + 1] == '\0')
			return (1);
		if (str[i + j] == '\n' && str[i + j + 1] == '\n'
				&& (str[i + j + 2] == '.' || str[i + j + 2] == '#'))
			j += 21;
		else
			return (0);
		i = 0;
	}
	return (1);
}

int		check_piece(char **matrix, t_tetrix *tet, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (tet->y[i] < size && tet->x[i] < size &&
					matrix[tet->y[i]][tet->x[i]] == '.')
			{
				i++;
				if (i == 4)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
