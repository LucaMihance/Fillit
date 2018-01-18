/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstan-po <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 14:09:43 by dstan-po          #+#    #+#             */
/*   Updated: 2018/01/09 14:37:42 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_size(char *file)
{
	int		i;
	int		fd;
	char	buff;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &buff, 1) != '\0')
	{
		if (buff != '\n' && buff != '.' && buff != '#')
			return (-1);
		i++;
	}
	close(fd);
	if (i > 545)
		return (-1);
	return (i);
}

int		ft_read(char *file)
{
	int		i;
	int		fd;
	char	buff;
	char	*tetrimino;

	i = 0;
	if (ft_size(file) < 0)
		return (-1);
	tetrimino = (char*)ft_memalloc(ft_size(file) + 1);
	if (tetrimino == NULL)
		return (-1);
	fd = open(file, O_RDONLY);
	while (read(fd, &buff, 1) != '\0')
	{
		if (buff != '\n' && buff != '.' && buff != '#')
			return (-1);
		tetrimino[i++] = buff;
	}
	tetrimino[i] = '\0';
	close(fd);
	if (tetrimino[0] != '.' && tetrimino[0] != '#')
		return (-1);
	return (0);
}

int		ft_error(void)
{
	ft_putendl("error");
	exit(0);
}
