/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:36:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/09 12:13:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

static t_list	*wctobl
	(wchar_t wc)
{
	t_list		*ret;
	size_t		i;
	wchar_t		mask;
	char		*buf;

	if (wc < 0x80)
		return (ft_lstnew(&wc, 1));
	if (!(ret = ft_memalloc(sizeof(*ret))))
		return (NULL);
	ret->content_size = 2;
	while (ret->content_size <= 4 && wc >> ret->content_size * 6)
		ret->content_size++;
	i = ret->content_size;
	if (!(buf = malloc(ret->content_size)))
		return (NULL);
	mask = 0;
	while (i)
		mask |= 1 << (8 - i--);
	i = ret->content_size - 1;
	*buf++ = mask | (wc >> 6 * i--);
	while (i)
		*buf++ = 0x80 | (wc >> 6 * i-- & 0x3F);
	*buf = 0x80 | (wc & 0x3F);
	ret->content = buf - ret->content_size + 1;
	return (ret);
}

t_list			*wc_conv
	(t_parse_result *p)
{
	return (wctobl((wchar_t)p->ctxt.arg));
}

t_list			*ws_build
	(t_parse_result *p, t_list *ret)
{
	size_t		len;
	t_list		**alst;

	if (!p->ctxt.prec_given)
		return (ft_lstbuild(ret) ? ret : NULL);
	alst = &ret;
	len = ret->content_size;
	while (len <= p->ctxt.prec)
	{
		alst = &(*alst)->next;
		if (!(*alst))
			break;
		len += (*alst)->content_size;
	}
	ft_lstdel(alst, &ft_delete);
	return (ft_lstbuild(ret) ? ret : NULL);
}

t_list			*ws_conv
	(t_parse_result *p)
{
	wchar_t		*arg;
	size_t		len;
	t_list		*ret;

	if (!p->ctxt.prec)
		return (NULL);
	if (!p->ctxt.arg)
		return (ft_lstnew("(null)", 6));
	arg = (wchar_t *)p->ctxt.arg;
	len = ft_wstrlen(arg);
	if (!len)
		return (NULL);
	ret = NULL;
	while (len)
		ft_lstadd(&ret, wctobl(arg[--len]));
	return (ret ? ws_build(p, ret) : NULL);
}
