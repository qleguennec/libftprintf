/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_attrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/19 15:34:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static t_list	*sharp_attr
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	char		s[3];

	if (!ctxt->arg)
		return (NULL);
	ft_bzero(s, 3);
	if (self->name[0] == 'x' || self->name[0] == 'p')
		ft_strcpy(s, "0x");
	else if (self->name[0] == 'X')
		ft_strcpy(s, "0X");
	else
		return (NULL);
	return (ft_lstnew(s, ft_strlen(s)));
}

t_list			*eval_attrs_post
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	char		sign;
	t_list		*l;

	l = NULL;
	sign = 0;
	ctxt->attrs &= self->valid_attrs;
	if (SHARP_MASK & ctxt->attrs || self->name[0] == 'p')
		ft_lstadd(&l, sharp_attr(self, ctxt));
	if (ctxt->neg)
		sign = '-';
	else if (PLUS_MASK & ctxt->attrs)
		sign = '+';
	else if (SPACE_MASK & ctxt->attrs)
		sign = ' ';
	if (sign)
		ft_lstadd(&l, ft_lstnew(&sign, 1));
	return (l);
}
