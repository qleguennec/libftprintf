/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_self->attrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/04 23:23:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static t_list	*sharp_attr
	(t_conv_spec *self)
{
	char		s[3];

	if (!self->arg)
		return (NULL);
	ft_bzero(s, 3);
	if (self->name[0] == 'o')
		*s = '0';
	else if (self->name[0] == 'x' || self->name[0] == 'p')
		ft_strcpy(s, "0x");
	else if (self->name[0] == 'X')
		ft_strcpy(s, "0X");
	else
		return (NULL);
	return (ft_lstnew(s, ft_strlen(s)));
}

t_list			*eval_attrs
	(t_conv_spec *self)
{
	char		sign;
	t_list		*l;

	l = NULL;
	sign = 0;
	self->attrs &= self->valid_attrs;
	if (SHARP_MASK & self->attrs)
		ft_lstadd(&l, sharp_attr(self));
	if (self->neg && (PLUS_MASK & self->valid_attrs))
		sign = '-';
	else if (PLUS_MASK & self->attrs)
		sign = '+';
	else if (SPACE_MASK & self->attrs)
		sign = ' ';
	if (sign)
		ft_lstadd(&l, ft_lstnew(&sign, 1));
	return (l);
}
