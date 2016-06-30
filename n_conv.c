/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 18:55:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 14:08:10 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_intern.h"

int			n_conv
	(t_parse_result *p, t_vect *v)
{
	void	*a;
	size_t	size;

	size = p->ctxt.l_modif ? p->ctxt.l_modif->size : p->conv->size;
	a = (void *)p->ctxt.arg.g;
	ft_memcpy(a, &v->used, size);
	return (1);
}
