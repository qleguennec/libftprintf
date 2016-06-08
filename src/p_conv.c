/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/08 20:03:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

t_list					*p_conv
	(t_parse_result *p)
{
	size_t				len;
	size_t				base;
	t_list				*ret;
	size_t				arg;

	if (!p->ctxt.prec)
		return (ft_lstnew("0x", 2));
	arg = p->ctxt.arg;
	base = ft_strlen(g_alphabets[p->conv->base]);
	len = ZERO_MASK & p->ctxt.attrs
		? ft_max(p->ctxt.width, ft_max(p->ctxt.prec, digits_nb(arg, base)) + 2)
		: ft_max(p->ctxt.prec, digits_nb(arg, base)) + 2;
	if (!(ret = ft_lstnew(NULL, len)))
		return (NULL);
	ft_memset(ret->content, '0', len);
	((char *)ret->content)[1] = 'x';
	while (len && arg >= base)
	{
		((char *)ret->content)[--len] =
			*(g_alphabets[p->conv->base] + arg % base);
		arg /= base;
	}
	((char *)ret->content)[--len] = *(g_alphabets[p->conv->base] + arg);
	ret->content = ret->content;
	return (ret);
}
