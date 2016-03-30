/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 19:31:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

void		fill
	(t_vect *builder, char c, int right, size_t width)
{
	t_list	*l;
	int		len;

	len = builder->size - width;
	if (len <= 0)
		return ;
	if (!(l = ft_lstnew(NULL, len)))
		p_exit(PRINTF_ERR_MALLOC, " in function fill");
	ft_memset(l->content, c, len);
	if (!right)
		ft_lstadd((t_list **)&builder->content, l);
	else
		ft_lstadd_end((t_list **)&builder->content, l);
	builder->size += len;
}
