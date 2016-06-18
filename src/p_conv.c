/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/18 15:15:36 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

int				p_conv
	(t_parse_result *p, t_vect **v)
{
	size_t		len;
	size_t		arg;
	t_vect		*w;
	char		*buf;

	if (!p->ctxt.prec)
		return (vect_addstr(v, "0x"));
	arg = p->ctxt.arg;
	len = ZERO_MASK & p->ctxt.attrs
		? MAX(p->ctxt.width, MAX(p->ctxt.prec, digits_nb(arg, 16)) + 2)
		: MAX(p->ctxt.prec, digits_nb(arg, 16)) + 2;
	if (!(vect_memset(v, '0', len, 0)))
		return (0);
	w = *v;
	((char *)w->data)[1] = 'x';
	buf = w->data;
	while (len && arg >= 16)
	{
		buf[--len] = *(g_alphabets[p->conv->base] + arg % 16);
		arg /= 16;
	}
	buf[--len] = *(g_alphabets[p->conv->base] + arg);
	return (1);
}
