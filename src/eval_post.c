/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_attrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/25 19:08:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

static char		get_width_letter
	(t_parse_result *p)
{
	if (!p->conv)
		return (ATTR(ZERO) ? '0' : ' ');
	if (MINUS & p->ctxt.attrs)
		return (' ');
	else
		return (p->conv && (p->conv->size <= 2 || !p->ctxt.prec_given)
			&& ATTR(ZERO) ? '0' : ' ');
}

static int		sharp_attr
	(t_parse_result *p, t_vect *v)
{
	char		buf[2];
	char		letter;
	size_t		size;

	if (!p->ctxt.arg.g)
		return (1);
	if (p->conv->name[0] == 'x')
		ft_memcpy(buf, "0x", 2);
	else if (p->conv->name[0] == 'X')
		ft_memcpy(buf, "0X", 2);
	else
		return (1);
	if (!vect_push(v, buf, 2, p->ctxt.s))
		return (0);
	size = v->used - p->ctxt.s;
	if (p->ctxt.width <= size)
		return (1);
	letter = get_width_letter(p);
	if (letter == ' ')
		return (vect_mset(v, letter, size, ATTR(MINUS) ? v->used : p->ctxt.s));
	return (vect_mset(v, letter, p->ctxt.width - size, p->ctxt.s + 2));
}

static int		no_conv
	(t_parse_result *p, t_vect *v)
{
	return (p->ctxt.width <= size ? 1 : vect_mset(v, get_width_letter(p),
		p->ctxt.width - size, ATTR(MINUS) + p->ctxt.s));
}

int				eval_post
	(t_parse_result *p, t_vect *v)
{
	char		sign;
	size_t		n;
	size_t		size;

	sign = 0;
	size = v->used - p->ctxt.s;
	if (!p->conv)
		return (no_conv);
	p->ctxt.attrs &= p->conv->valid_attrs;
	if (ATTR(SHARP))
		return (sharp_attr(p, v));
	if (p->ctxt.neg)
		sign = '-';
	else if (ATTR(PLUS))
		sign = '+';
	else if (p->conv && ATTR(SPACE))
		sign = ' ';
	if (sign && !vect_mset(v, sign, 1, p->ctxt.s))
		return (0);
	size = v->used - p->ctxt.s;
	if (p->ctxt.width <= size)
		return (1);
	n = ATTR(MINUS) ? v->used : p->ctxt.s + (sign && ATTR(ZERO));
	return (vect_mset(v, get_width_letter(p), p->ctxt.width - size, n));
}
