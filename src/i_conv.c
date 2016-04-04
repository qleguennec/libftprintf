/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/05 01:54:08 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static t_arg			get_mask
	(size_t size)
{
	t_arg				mask;
	size_t				i;

	i = 0;
	mask = 0;
	while (i < size * 8)
		mask |= (t_arg)1 << i++;
	return (mask);
}

static t_arg		abs_value
	(t_conv_spec *self)
{
	t_arg				ret;
	t_arg				mask;

	ret = self->arg;
	mask = get_mask(self->size);
	if ((PLUS_MASK & self->valid_attrs)
		&& (ret >> (8 * self->size - 1)))
	{
		ret = mask & (~ ret) + 1;
		self->neg = 1;
	}
	return (ret);
}

t_list					*i_conv
	(t_conv_spec *self)
{
	t_list				*ret;
	size_t				len;
	size_t				base;
	t_arg				y;

	if (!self->arg)
		return (null_case(self));
	base = ft_strlen(alphabets[self->base]);
	y = abs_value(self);
	len = digits_nb(y, base);
	if (!(ret = ft_lstnew(NULL, len)))
		return (NULL);
	ret->content += len;
	while (y >= base)
	{
		ret->content--;
		(*(char *)ret->content) =
			*(alphabets[self->base] + y % base);
		y /= base;
	}
	ret->content--;
	(*(char *)ret->content) = *(alphabets[self->base] + y);
	return (ret);
}
