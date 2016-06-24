/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 02:11:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 13:18:54 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

int				c_conv
	(t_parse_result *p, t_vect **v)
{
	if (p->ctxt.l_modif && ft_strequ(p->ctxt.l_modif->name, "l"))
		return (wc_conv(p, v));
	return (vect_memset(v, (unsigned char)p->ctxt.arg.g, 1, 0));
}

int				s_conv
	(t_parse_result *p, t_vect **v)
{
	size_t		len;

	if (!p->ctxt.prec)
		return (1);
	if (!p->ctxt.arg.g)
		return (vect_addstr(v, "(null)"));
	if (p->conv->ismodif_length && p->ctxt.l_modif
		&& ft_strequ(p->ctxt.l_modif->name, "l"))
		return (ws_conv(p, v));
	if (p->ctxt.prec_given)
		len = MIN(p->ctxt.prec, ft_strlen((char *)p->ctxt.arg.g));
	else
		len = ft_strlen((char *)p->ctxt.arg.g);
	return (vect_add(v, (void *)p->ctxt.arg.g, len));
}
