/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:41:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/23 16:45:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <libftprintf.h>
#include <stdio.h>

int				f_conv
	(t_parse_result *p, t_vect **v)
{
	int			k;
	double		x;
	int			finite;
	void		*a;
	size_t		prec;

	x = p->ctxt.arg.d;
	if ((finite = fp_isfinite(v, x, ft_isupper(*p->conv->name))))
		return (finite == 1 ? 1 : 0);
	if (x < 0)
	{
		x = -x;
		p->ctxt.neg = 1;
	}
	p->ctxt.prec = p->ctxt.prec_given ? p->ctxt.prec : 6;
	prec = p->ctxt.prec;
	k = 0;
	if (!(fp_digits(v, p, x, &k)))
		return (0);
	if ((*v)->used > 1 && (k < 0 || (size_t)k < p->ctxt.prec))
		k = vect_pushstr(v, ".", k > 0 ? k : 1);
	if ((a = ft_memchr((*v)->data, '.', (*v)->used))
		&& a++
		&& (size_t)(((*v)->data + (*v)->used) - a) > prec)
		(*v)->used--;
	return (k);
}
