/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actualread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstan-po <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 15:27:46 by dstan-po          #+#    #+#             */
/*   Updated: 2018/01/09 14:39:55 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			count_tetrix(char *str)
{
	int	i;
	int	hash;

	i = 0;
	hash = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			hash++;
		i++;
	}
	return (hash / 4);
}

void		set_tetrix_lst(t_tetrix **temp, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			(*temp)->x[j] = i % 5;
			(*temp)->y[j] = i / 5;
			j++;
		}
		i++;
	}
}

t_tetrix	*str_tetrix(char *tetrimino)
{
	int			c_tetrix;
	int			and_more;
	char		c;
	t_tetrix	*pile;
	t_tetrix	*temp;

	and_more = 0;
	c = 'A';
	c_tetrix = count_tetrix(tetrimino);
	if (!(pile = (t_tetrix*)malloc(sizeof(t_tetrix))))
		return (NULL);
	temp = pile;
	while (c_tetrix > 0)
	{
		temp->c = c;
		set_tetrix_lst(&temp, ft_strsub(tetrimino, and_more, 20));
		if (!(temp->next = (t_tetrix*)malloc(sizeof(t_tetrix))))
			return (NULL);
		temp = temp->next;
		c_tetrix--;
		c++;
		and_more += 21;
	}
	temp->next = NULL;
	return (pile);
}

char		*read_file(int fd)
{
	int		i;
	int		el;
	char	c;
	char	*tetrimino;

	i = 0;
	tetrimino = NULL;
	el = read(fd, &c, 1);
	if (el < 0)
		return (NULL);
	if (el == 1)
	{
		tetrimino = (char*)malloc(sizeof(char) * 545);
		while (el != '\0')
		{
			tetrimino[i] = c;
			i++;
			el = read(fd, &c, 1);
		}
		tetrimino[i] = '\0';
	}
	return (tetrimino);
}
