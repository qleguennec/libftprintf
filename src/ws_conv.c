/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:36:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/21 11:18:53 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

static int		wctovect
	(t_vect **v, wchar_t wc)
{
	size_t		i;
	size_t		size;
	wchar_t		mask;

	if (wc < 0x80)
		return (vect_memset(v, (unsigned char)wc, 1, *v ? (*v)->used : 0));
	size = 2;
	while (size <= 4 && wc >> size * 6)
		size++;
	i = size;
	if (!vect_req(v, size))
		return (0);
	mask = 0;
	while (i)
		mask |= 1 << (8 - i--);
	i = size - 1;
	((char *)(*v)->data)[(*v)->used++] = mask | (wc >> 6 * i--);
	while (i)
		((char *)(*v)->data)[(*v)->used++] = 0x80 | (wc >> 6 * i-- & 0x3F);
	((char *)(*v)->data)[(*v)->used++] = 0x80 | (wc & 0x3F);
	return (1);
}

int				wc_conv
	(t_parse_result *p, t_vect **v)
{
	return (wctovect(v, (wchar_t)p->ctxt.arg.g));
}

int				ws_conv
	(t_parse_result *p, t_vect **v)
{
	size_t		i;
	size_t		len;
	size_t		old_size;
	size_t		bytes;

	if (!p->ctxt.prec)
		return (1);
	if (!p->ctxt.arg.g)
		return (vect_addstr(v, "(null)"));
	len = ft_wstrlen((wchar_t*)p->ctxt.arg.g);
	if (!len || (p->ctxt.prec_given && !p->ctxt.prec))
		return (1);
	i = 0;
	bytes = 0;
	while (i < len)
	{
		old_size = (*v) ? (*v)->used : 0;
		if (!(wctovect(v, ((wchar_t*)p->ctxt.arg.g)[i++])))
			return (0);
		bytes += (*v)->used - old_size;
		if (p->ctxt.prec_given && bytes > p->ctxt.prec)
			return (((*v)->used = old_size) || 1);
	}
	return (1);
}
