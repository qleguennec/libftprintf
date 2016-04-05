/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 02:11:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/05 23:46:39 by qle-guen         ###   ########.fr       */
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
	len = ft_min(ctxt->prec, ft_strlen((char *)self->arg));
	return (ft_lstnew((char *)self->arg, len));
}
