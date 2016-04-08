/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:36:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/08 21:58:50 by qle-guen         ###   ########.fr       */
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
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	if (!ctxt->arg)
		return (null_case(self));
	return (wctobl((wchar_t)ctxt->arg));
}

t_list		*ws_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	wchar_t	*arg;
	size_t	len;
	t_list	*ret;

	if (!ctxt->arg)
		return (null_case(self));
	len = ft_wstrlen((const wchar_t *)ctxt->arg);
	if (!len)
		return (ft_lstnew("", 1));
	arg = (wchar_t *)ctxt->arg;
	ret = NULL;
	while (len)
		ft_lstadd(&ret, wctobl(arg[--len]));
	assert(ret != NULL);
	ft_lstbuild(ret);
	return (ret);
}
