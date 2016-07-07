/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/05 18:32:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf_intern.h"

static size_t			get_mask
	(size_t size)
{
	size_t				mask;
	size_t				i;

	i = 0;
	mask = 0;
	while (i < size * 8)
		mask |= (size_t)1 << i++;
	return (mask);
}

static size_t			abs_value
	(t_parse_result *p)
{
	size_t				ret;
	size_t				mask;
	size_t				size;

	size = (p->conv->ismodif_length && p->ctxt.l_modif)
		? p->ctxt.l_modif->size : p->conv->size;
	ret = p->ctxt.arg.g;
	mask = get_mask(size);
	ret &= mask;
	if ((PLUS & p->conv->valid_attrs)
		&& (ret >> (8 * size - 1)))
	{
		ret = mask & (~ret) + 1;
		p->ctxt.neg = 1;
	}
	return (ret);
}

static size_t			get_digit_prec
	(t_parse_result *p, size_t x, size_t base)
{
	size_t				len;

	if (!p->ctxt.prec && !p->ctxt.arg.g)
		len = 0;
	else
		len = MAX(p->ctxt.prec, digits_nb(x, base));
	if ((ATTR(SHARP))
		&& (!p->ctxt.prec_given || !p->ctxt.prec)
		&& (x || !p->ctxt.prec)
		&& (ft_tolower(*p->conv->name) == 'o'))
	{
		len++;
		p->ctxt.attrs &= ~SHARP;
	}
	return (len);
}

int						i_conv
	(t_parse_result *p, t_vect *v)
{
	char				*buf;
	size_t				y;
	size_t				len;
	size_t				base;

	y = abs_value(p);
	base = ft_strlen(g_alphabets[p->conv->base]);
	if (!(len = get_digit_prec(p, y, base)))
		return (vect_mset(v, ' ', p->ctxt.width, v->used));
	if (!(vect_mset(v, '0', len, p->ctxt.s)))
		return (0);
	buf = v->data + p->ctxt.s;
	while (len && y >= base)
	{
		buf[--len] = *(g_alphabets[p->conv->base] + y % base);
		y /= base;
	}
	buf[--len] = *(g_alphabets[p->conv->base] + y);
	return (1);
}
