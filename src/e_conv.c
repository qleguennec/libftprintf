/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 18:41:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/23 17:55:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

static int		fmt_e
	(t_parse_result *p, t_vect **v, double x)
{
	int			k;
	char		*buf;

	k = 0;
	if (!(fp_whole(v, &x, &k, 0)))
		return (0);
	if (!(fp_frac(v, x, 0, p->ctxt.prec + 1)
		&& (!p->ctxt.prec || vect_memset(v, '.', 1, 1))))
		return (0);
	if (p->ctxt.prec == 0 && k < 0 && (*v)->used == 1
		&& ((char *)(*v)->data)[0] == '1')
		k = 0;
	buf = NULL;
	if ((ft_asprintf(&buf, "%c%+.2d", *p->conv->name, k)) == -1)
		return (0);
	vect_addstr(v, buf);
	free(buf);
	return (1);
}

int				e_conv
	(t_parse_result *p, t_vect **v)
{
	double		x;
	int			finite;

	if (!(*v || (*v = ft_memalloc(sizeof(**v)))))
		return (0);
	x = p->ctxt.arg.d;
	if ((finite = fp_isfinite(v, x, ft_isupper(*p->conv->name))))
		return (finite == 1 ? 1 : 0);
	if (x < 0)
	{
		x = -x;
		p->ctxt.neg = 1;
	}
	p->ctxt.prec = p->ctxt.prec_given ? p->ctxt.prec : 6;
	return (fmt_e(p, v, x));
}
