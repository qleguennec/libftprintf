/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 19:24:38 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 16:20:49 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list		*percent
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	(void)self;
	(void)ctxt;
	return (ft_lstnew("%", 1));
}
