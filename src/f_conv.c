/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:41:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/20 19:03:25 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <stdio.h>

int					f_conv
	(t_parse_result *p, t_vect **v)
{
	size_t			width;
	double			x;
	t_vect			*w;
	t_vect			*f;

	(void)v;
	x = p->ctxt.arg.d;
	width = p->ctxt.prec_given ? p->ctxt.prec : 6;
	if (!((w = fp_whole(&x)) && (f = fp_frac(x, width))))
		return (0);
	if (f->used && !(vect_addstr(&w, ".") && vect_add(&w, f->data, f->used)))
		return (0);
	vect_del(&f);
	if (*v)
		return (vect_add(v, w->data, w->used));
	*v = w;
	return (1);
}
