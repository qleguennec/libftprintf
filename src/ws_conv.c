/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:36:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 13:48:39 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list		*wctobl
	(wchar_t wc)
{
	t_list	*ret;
	size_t	i;
	wchar_t	mask;
	char	*buf;

	if (wc < 0x80)
		return (ft_lstnew(&wc, 1));
	if (!(ret = malloc(sizeof(*ret))))
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

t_list		*wc_conv
	(t_parse_result *p)
{
	if (!p->ctxt.arg)
		return (null_case(p->conv));
	return (wctobl((wchar_t)p->ctxt.arg));
}

t_list		*ws_conv
	(t_parse_result *p)
{
	wchar_t	*arg;
	size_t	len;
	t_list	*ret;

	if (!p->ctxt.arg)
		return (null_case(p->conv));
	len = ft_wstrlen((const wchar_t *)p->ctxt.arg);
	if (!len)
		return (NULL);
	arg = (wchar_t *)p->ctxt.arg;
	ret = NULL;
	while (len)
		ft_lstadd(&ret, wctobl(arg[--len]));
	ft_lstbuild(ret);
	return (ret);
}
