/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstan-po <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:03:14 by dstan-po          #+#    #+#             */
/*   Updated: 2018/01/03 17:41:46 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char		*str;
	int			fd;
	t_tetrix	*tet;

	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	if (ft_read(argv[1]) == -1)
		ft_error();
	fd = open(argv[1], O_RDONLY);
	str = read_file(fd);
	if (!check_str(str))
		ft_error();
	close(fd);
	tet = str_tetrix(str);
	solve(tet);
	free(tet);
	free(str);
	return (0);
}
