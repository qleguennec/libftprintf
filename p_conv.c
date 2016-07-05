/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/07/05 18:33:11 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_intern.h"

int				p_conv
	(t_parse_result *p, t_vect *v)
{
	size_t		len;
	size_t		arg;
	char		*buf;

	if (!p->ctxt.prec)
		return (vect_addstr(v, "0x"));
	arg = (size_t)p->ctxt.arg.g;
	len = ATTR(ZERO)
		? MAX(p->ctxt.width, MAX(p->ctxt.prec, digits_nb(arg, 16)) + 2)
		: MAX(p->ctxt.prec, digits_nb(arg, 16)) + 2;
	if (!(vect_mset(v, '0', len, p->ctxt.s)))
		return (0);
	buf = v->data + p->ctxt.s;
	buf[1] = 'x';
	while (len && arg >= 16)
	{
		buf[--len] = *(g_alphabets[p->conv->base] + arg % 16);
		arg /= 16;
	}
	buf[--len] = *(g_alphabets[p->conv->base] + arg);
	return (1);
}
