/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmihance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:08:58 by lmihance          #+#    #+#             */
/*   Updated: 2017/12/20 16:16:16 by lmihance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*e;

	e = (t_list*)ft_memalloc(sizeof(t_list));
	if (e == NULL)
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		e->content = NULL;
	}
	else
	{
		e->content = ft_memalloc(content_size);
		if (e->content == NULL)
		{
			ft_memdel((void**)&e);
			return (NULL);
		}
		ft_memcpy(e->content, content, content_size);
	}
	e->content_size = content_size;
	e->next = NULL;
	return (e);
}
