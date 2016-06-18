/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_attrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/18 16:10:09 by qle-guen         ###   ########.fr       */
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
	char		letter;
	t_vect		*w;

	w = *v;
	if (!p->ctxt.arg)
		return (1);
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
	letter = get_width_letter(p);
	if (letter == ' ')
		return (vect_memset(v, letter, p->ctxt.width - w->used
			, MINUS_MASK & p->ctxt.attrs ? w->used : 0));
	return (vect_memset(v, letter, p->ctxt.width - w->used , 2));
}

int				eval_post
	(t_parse_result *p, t_vect **v)
{
	char		sign;
	size_t		n;

	sign = 0;
	if (!(*v || (*v = ft_memalloc(sizeof(**v))) != NULL))
		return (0);
	if (p->conv)
		p->ctxt.attrs &= p->conv->valid_attrs;
	if (p->conv && SHARP_MASK & p->ctxt.attrs)
		return (sharp_attr(p, v));
	if (p->ctxt.neg)
		sign = '-';
	else if (PLUS_MASK & p->ctxt.attrs)
		sign = '+';
	else if (p->conv && SPACE_MASK & p->ctxt.attrs)
		sign = ' ';
	if (sign && !vect_memset(v, sign, 1, 0))
		return (0);
	if (p->ctxt.width <= (*v)->used)
		return (1);
	if (sign && ZERO_MASK & p->ctxt.attrs)
		n = MINUS_MASK & p->ctxt.attrs ? (*v)->used : 1;
	else
		n = MINUS_MASK & p->ctxt.attrs ? (*v)->used : 0;
	return (vect_memset(v, get_width_letter(p), p->ctxt.width - (*v)->used, n));
}
