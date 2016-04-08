/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 02:11:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/08 14:08:51 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list			*c_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	char		arg[1];

	if (!ctxt->arg)
		return (null_case(self));
	if (ctxt->l_modif && ft_strequ(ctxt->l_modif->name, "l"))
		return (wc_conv(self, ctxt));
	arg[0] = (char)ctxt->arg;
	return (ft_lstnew(arg, 1));
}

t_list			*s_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	size_t		len;

	if (!ctxt->arg)
		return (null_case(self));
	if (ctxt->l_modif && ft_strequ(ctxt->l_modif->name, "l"))
		return (wstr_conv(self, ctxt));
	if (ctxt->prec)
		len = ft_min(ctxt->prec, ft_strlen((char *)ctxt->arg));
	else
		len = ft_strlen((char *)ctxt->arg);
	return (ft_lstnew((char *)ctxt->arg, len));
}
