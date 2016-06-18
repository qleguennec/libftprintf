/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:36:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/18 02:28:25 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

static int		wctovect
	(t_vect **v, wchar_t wc)
{
	size_t		i;
	size_t		size;
	wchar_t		mask;
	char		*buf;

	if (wc < 0x80)
		return (vect_memset(v, (unsigned char)wc, 1, (*v)->used));
	size = 2;
	while (size <= 4 && wc >> size * 6)
		size++;
	i = size;
	buf = (*v)->data + (*v)->used;
	if (!vect_req(*v, size))
		return (0);
	mask = 0;
	while (i)
		mask |= 1 << (8 - i--);
	i = size - 1;
	*buf++ = mask | (wc >> 6 * i--);
	while (i)
		*buf++ = 0x80 | (wc >> 6 * i-- & 0x3F);
	*buf = 0x80 | (wc & 0x3F);
	return (1);
}

int				wc_conv
	(t_parse_result *p, t_vect **v)
{
	return (wctovect(v, (wchar_t)p->ctxt.arg));
}

int				ws_conv
	(t_parse_result *p, t_vect **v)
{
	wchar_t		*arg;
	size_t		i;
	size_t		len;

	if (!p->ctxt.prec)
		return (0);
	if (!p->ctxt.arg)
		return (vect_addstr(v, "(null)"));
	arg = (wchar_t *)p->ctxt.arg;
	len = p->ctxt.prec_given ? MIN(ft_wstrlen(arg), p->ctxt.prec)
		: ft_wstrlen(arg);
	if (!len)
		return (0);
	i = 0;
	while (i < len)
	{
		if (!(wctovect(v, arg[i++])))
			return (0);
	}
	return (1);
}
