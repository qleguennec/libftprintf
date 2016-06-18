/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_attrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/18 02:26:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

static char		get_width_letter
	(t_parse_result *p)
{
	if (!p->conv)
		return (ZERO_MASK & p->ctxt.attrs ? '0' : ' ');
	if (MINUS_MASK & p->ctxt.attrs)
		return (' ');
	else
		return (p->conv && (p->conv->size <= 1 || !p->ctxt.prec_given)
			&& ZERO_MASK & p->ctxt.attrs ? '0' : ' ');
}

static int		sharp_attr
	(t_parse_result *p, t_vect **v)
{
	char		buf[2];
	t_vect		*w;

	w = *v;
	if (p->conv->name[0] == 'x')
		ft_memcpy(buf, "0x", 2);
	else if (p->conv->name[0] == 'X')
		ft_memcpy(buf, "0X", 2);
	else
		return (1);
	if (!vect_push(v, buf, 2, 0))
		return (0);
	if (p->ctxt.width <= w->used)
		return (1);
	return (vect_memset(v, get_width_letter(p), p->ctxt.width - w->used , 2));
}

int				eval_post
	(t_parse_result *p, t_vect **v)
{
	char		sign;
	size_t		n;
	t_vect		*w;

	sign = 0;
	p->ctxt.attrs &= p->conv->valid_attrs;
	if (SHARP_MASK & p->ctxt.attrs)
		return (sharp_attr(p, v));
	if (p->ctxt.neg)
		sign = '-';
	else if (PLUS_MASK & p->ctxt.attrs)
		sign = '+';
	else if (SPACE_MASK & p->ctxt.attrs)
		sign = ' ';
	w = *v;
	if (sign && !vect_memset(v, sign, 1, 0))
		return (0);
	if (p->ctxt.width <= w->used)
		return (1);
	n = MINUS_MASK & p->ctxt.attrs ? w->used : 0;
	return (vect_memset(v, get_width_letter(p), p->ctxt.width - w->used, n));
}
