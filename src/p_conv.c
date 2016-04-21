/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/21 15:59:51 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list					*p_conv
	(t_parse_result *p)
{
	size_t				len;
	size_t				base;
	t_list				*ret;
	char				*buf;
	size_t				arg;

	if (!p->ctxt.prec)
		return (ft_lstnew("0x", 2));
	arg = p->ctxt.arg;
	base = ft_strlen(alphabets[p->conv->base]);
	len = ft_max(p->ctxt.prec, digits_nb(arg, base)) + 2;
	if (!(ret = ft_lstnew(NULL, len)))
		return (NULL);
	buf = malloc(len);
	ft_memset(buf, '0', len);
	buf[1] = 'x';
	while (len && arg >= base)
	{
		buf[--len] = *(alphabets[p->conv->base] + arg % base);
		arg /= base;
	}
	buf[--len] = *(alphabets[p->conv->base] + arg);
	ret->content = buf;
	return (ret);
}
