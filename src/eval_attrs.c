/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_attrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/03 02:11:01 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static t_list	*sharp_attr
	(t_conv_spec *self, void *x)
{
	char		s[3];

	if (!x)
		return (NULL);
	ft_bzero(s, 3);
	if (self->name == 'o')
		*s = '0';
	else if (self->name == 'x')
		ft_strcpy(s, "0x");
	else if (self->name == 'X')
		ft_strcpy(s, "0X");
	else
		return (NULL);
	return (ft_lstnew(s, ft_strlen(s)));
}

t_list			*eval_attrs
	(t_conv_spec *self, void *x, t_attrs attrs)
{
	char		sign;
	t_list		*l;

	l = NULL;
	sign = 0;
	if ((1 << SHARP_OFFSET) & attrs)
		ft_lstadd(&l, sharp_attr(self, x));
	if (self->sign >> 1)
		sign = '-';
	else if ((1 << PLUS_OFFSET) & attrs)
		sign = '+';
	else if ((1 << SPACE_OFFSET) & attrs)
		sign = ' ';
	if (sign)
		ft_lstadd(&l, ft_lstnew(&sign, 1));
	return (l);
}
