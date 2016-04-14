/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/14 12:48:54 by qle-guen         ###   ########.fr       */
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

static t_arg			abs_value
	(t_parse_result *p)
{
	t_arg				ret;
	t_arg				mask;
	size_t				size;

	size = (p->conv->ismodif_length && p->ctxt.l_modif)
		? p->ctxt.l_modif->size : p->conv->size;
	ret = p->ctxt.arg;
	mask = get_mask(size);
	ret &= mask;
	if ((PLUS_MASK & p->conv->valid_attrs)
		&& (ret >> (8 * size - 1)))
	{
		ret = mask & (~ret) + 1;
		p->ctxt.neg = 1;
	}
	return (ret);
}

t_list					*i_conv
	(t_parse_result *p)
{
	t_list				*ret;
	char				*buf;
	t_arg				y;
	size_t				len;
	size_t				base;

	if (!p->ctxt.arg)
		return (null_case(p->conv));
	y = abs_value(p);
	base = ft_strlen(alphabets[p->conv->base]);
	len = ft_max(p->ctxt.prec, digits_nb(y, base));
	if (!(ret = ft_lstnew(NULL, len)))
		return (NULL);
	buf = malloc(len);
	ft_memset(buf, '0', len);
	while (len && y >= base)
	{
		buf[--len] = *(alphabets[p->conv->base] + y % base);
		y /= base;
	}
	buf[--len] = *(alphabets[p->conv->base] + y);
	ret->content = buf;
	return (ret);
}
