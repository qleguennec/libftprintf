/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/18 15:32:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

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

static size_t			get_digit_prec
	(t_parse_result *p, t_arg x, size_t base)
{
	size_t				len;

	if (!p->ctxt.prec && !p->ctxt.arg)
		len = 0;
	else
		len = MAX(p->ctxt.prec, digits_nb(x, base));
	if ((SHARP_MASK & p->ctxt.attrs)
		&& (!p->ctxt.prec_given || !p->ctxt.prec)
		&& (x || !p->ctxt.prec)
		&& (p->conv->name[0] == 'o' || p->conv->name[0] == 'O'))
	{
		len++;
		p->ctxt.attrs &= ~SHARP_MASK;
	}
	return (len);
}

int						i_conv
	(t_parse_result *p, t_vect **v)
{
	char				*buf;
	t_arg				y;
	size_t				len;
	size_t				base;
	t_vect				*w;

	y = abs_value(p);
	base = ft_strlen(g_alphabets[p->conv->base]);
	if (!(len = get_digit_prec(p, y, base)))
		return (*v ? 1 : (*v = ft_memalloc(sizeof(**v))) != NULL);
	if (!(vect_memset(v, '0', len, 0)))
		return (0);
	w = *v;
	buf = w->data;
	while (len && y >= base)
	{
		buf[--len] = *(g_alphabets[p->conv->base] + y % base);
		y /= base;
	}
	buf[--len] = *(g_alphabets[p->conv->base] + y);
	return (1);
}
