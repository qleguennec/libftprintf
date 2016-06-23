/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:41:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/23 16:43:07 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <libftprintf.h>
#include <stdio.h>

/*
static int		fmt_e
	(t_vect **v, t_parse_result *p, int w)
{
	char		*buf;
	int			exp;
	t_vect		*new;

	new = NULL;
	if (!(buf = ft_memnchr((*v)->data, '0', (*v)->used)))
		buf = (*v)->data;
	vect_add(&new, buf++, 1);
	if ((*v)->used > 1)
		vect_addstr(&new, ".");
	vect_add(&new, buf, (*v)->data + (*v)->used - (void *)buf);
	vect_addstr(&new, ft_islower(*p->conv->name) ? "e" : "E");
	exp = w - (int)((void *)buf - (*v)->data);
	ft_asprintf(&buf, "%+0.2d", exp);
	if (!(buf && vect_addstr(&new, buf)))
		return (0);
	free(buf);
	vect_del(v);
	*v = new;
	return (1);
}
*/

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
