/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 02:11:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 02:08:57 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list			*s_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	size_t		len;

	if (!self->arg)
	{
		if (ctxt->prec)
			return (NULL);
		return (null_case(self));
	}
	if (ctxt->prec)
		len = ft_min(ctxt->prec, ft_strlen((char *)self->arg));
	else
		len = ft_strlen((char *)self->arg);
	return (ft_lstnew((void *)self->arg, len));
}
