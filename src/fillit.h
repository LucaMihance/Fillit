/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 14:43:30 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/29 17:33:27 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../includes/libft.h"
# include <fcntl.h>

typedef struct		s_st
{
	char			c;
	int				x[4];
	int				y[4];
	struct s_st		*next;
}					t_tetrix;

void				solve(t_tetrix *tet);
int					check_links(char *str, int j);
int					check_char_nbr(char *str, int j);
int					check_str(char *str);
int					check_piece(char **matrix, t_tetrix *tet, int size);
int					ft_size(char *file);
int					ft_read(char *file);
int					ft_error(void);
int					count_tetrix(char *str);
void				set_terix_lst(t_tetrix **temp, char *str);
t_tetrix			*str_tetrix(char *tetrimino);
char				*read_file(int fd);
char				**tetrix_matrix_new(char **matrix, int size);
char				**rm_tetrix(char **matrix, t_tetrix *tet, int size);
char				**ad_tetrix(char **matrix, t_tetrix *tet, int size);

#endif
