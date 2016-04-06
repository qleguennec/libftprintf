/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 16:10:26 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 16:23:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

int					get_conv_result
	(t_list **builder, t_ctxt_spec *ctxt)
{
	t_list			*l;
	char			letter;
	size_t			list_len;

	list_len = ft_lstsum(*builder);
	if ((unsigned int)ctxt->width <= list_len)
		return (ft_lstbuild(*builder));
	if (!(l = ft_lstnew(NULL, ctxt->width - list_len)))
		return (0);
	if (MINUS_MASK & ctxt->attrs)
		letter = ' ';
	else
		letter = ((ZERO_MASK & ctxt->attrs) ? '0' : ' ');
	ft_memset(l->content, letter, ctxt->width - list_len);
	if (letter == ' ' || !(*builder)->next
		|| ((MINUS_MASK) & ctxt->attrs))
	{
		if (MINUS_MASK & ctxt->attrs)
			return (ft_lstbuild(ft_lstadd_end(builder, l)));
		else
			return (ft_lstbuild(ft_lstadd(builder, l)));
	}
	l->next = (*builder)->next;
	(*builder)->next = l;
	return (ft_lstbuild(*builder));
}
