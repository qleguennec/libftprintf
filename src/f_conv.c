/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:41:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/21 17:51:00 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <libftprintf.h>
#include <stdio.h>

static int		fmt_e
	(t_vect **v, int w, int upper, size_t prec)
{
	char		*buf;
	int			exp;
	t_vect		*new;

	new = NULL;
	if (!(buf = ft_memnchr((*v)->data, '0', (*v)->used)))
		buf = (*v)->data;

		vect_add(&new, buf++, 1);
		vect_addstr(&new, ".");
		vect_add(&new, buf, (*v)->data + (*v)->used - (void *)buf);
		if (new->used - 2 < prec)
			vect_memset(&new, '0', prec - new->used + 2, new->used);
		vect_addstr(&new, upper ? "E" : "e");

	exp = w - (int)((void *)buf - (*v)->data);
	ft_asprintf(&buf, "%+0.2d", exp);
	if (!(buf && vect_addstr(&new, buf)))
		return (0);
	free(buf);
	vect_del(v);
	*v = new;
	return (1);
}

int				f_conv
	(t_parse_result *p, t_vect **v)
{
	size_t		prec;
	int			w;
	double		x;
	int			finite;

	x = p->ctxt.arg.d;
	if ((finite = fp_isfinite(v, x, ft_isupper(*p->conv->name))))
		return (finite == 1 ? 1 : 0);
	if (x < 0)
	{
		x = -x;
		p->ctxt.neg = 1;
	}
	prec = p->ctxt.prec_given ? p->ctxt.prec : 6;
	if (!(w = fp_digits(v, x, prec, ft_tolower(*p->conv->name == 'e'))))
		return (0);
	if (ft_tolower(*p->conv->name) == 'e')
		return (fmt_e(v, w, ft_isupper(*p->conv->name), prec));
	return (vect_memset(v, '.', 1, w));
}
