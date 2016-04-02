/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/02 13:09:46 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static unsigned long	get_mask
	(size_t size)
{
	unsigned long		mask;
	size_t				i;

	i = 0;
	mask = 0;
	while (i < size * 8)
		mask |= (unsigned long)1 << i++;
	return (mask);
}

static unsigned long	abs_value
	(t_conv_spec *self, void *x)
{
	unsigned long		ret;
	unsigned long		mask;

	ret = (unsigned long)x;
	mask = get_mask(self->size);
	if (self->sign & (ret >> (8 * self->size - 1)))
	{
		ret = mask & (~ ret) + 1;
		self->sign += 2;
	}
	return (ret);
}

t_list					*i_conv
	(t_conv_spec *self, void *x, size_t precision)
{
	t_list				*ret;
	size_t				len;
	size_t				base;
	unsigned long		y;

	(void)precision;
	base = ft_strlen(alphabets[self->base]);
	y = abs_value(self, x);
	len = digits_nb((void *)y, base);
	if (!(ret = ft_lstnew(NULL, len)))
		return (NULL);
	ret->content += len;
	while (y >= base)
	{
		ret->content--;
		(*(char *)ret->content) = *(alphabets[self->base] + y % base);
		y /= base;
	}
	ret->content--;
	(*(char *)ret->content) = *(alphabets[self->base] + y);
	return (ret);
}
