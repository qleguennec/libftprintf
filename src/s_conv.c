/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 02:11:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/08 23:55:52 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list			*c_conv
	(t_parse_result *p)
{
	char		arg[1];

	if (!p->ctxt.arg)
		return (null_case(p->conv));
	if (p->ctxt.l_modif && ft_strequ(p->ctxt.l_modif->name, "l"))
		return (wc_conv(p));
	arg[0] = (char)p->ctxt.arg;
	return (ft_lstnew(arg, 1));
}

t_list			*s_conv
	(t_parse_result *p)
{
	size_t		len;

	if (!p->ctxt.arg)
		return (null_case(p->conv));
	if (p->conv->ismodif_length && p->ctxt.l_modif
		&& ft_strequ(p->ctxt.l_modif->name, "l"))
		return (ws_conv(p));
	if (p->ctxt.prec)
		len = ft_min(p->ctxt.prec, ft_strlen((char *)p->ctxt.arg));
	else
		len = ft_strlen((char *)p->ctxt.arg);
	return (ft_lstnew((char *)p->ctxt.arg, len));
}
