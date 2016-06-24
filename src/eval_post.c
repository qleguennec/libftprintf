/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_attrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 13:26:28 by qle-guen         ###   ########.fr       */
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
		return (p->conv && (p->conv->size <= 1 || !p->ctxt.prec_given)
			&& ATTR(ZERO) ? '0' : ' ');
}

static int		sharp_attr
	(t_parse_result *p, t_vect **v)
{
	char		buf[2];
	char		letter;
	t_vect		*w;

	w = *v;
	if (!p->ctxt.arg.g)
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
			, ATTR(MINUS) ? w->used : 0));
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
	if (p->conv && ATTR(SHARP))
		return (sharp_attr(p, v));
	if (p->ctxt.neg)
		sign = '-';
	else if (ATTR(PLUS))
		sign = '+';
	else if (p->conv && ATTR(SPACE))
		sign = ' ';
	if (sign && !vect_memset(v, sign, 1, 0))
		return (0);
	if (p->ctxt.width <= (*v)->used)
		return (1);
	n = ATTR(MINUS) ? (*v)->used : (sign && ATTR(ZERO));
	return (vect_memset(v, get_width_letter(p), p->ctxt.width - (*v)->used, n));
}
