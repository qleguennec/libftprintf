/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:27:23 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/23 17:55:15 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <float.h>
#include <math.h>

int				fp_whole
	(t_vect **v, double *x, int *k, size_t prec)
{
	while (*x > 1.0 && ++(*k))
		*x /= 10;
	while (*x <= 1.0 && --(*k))
		*x *= 10;
	if (*k < 0 && prec)
		vect_memset(v, '0', -(*k), 0);
	return (1);
}

int				fp_frac
	(t_vect **v, double x, int k, size_t prec)
{
	size_t			n;

	n = 0;
	if (!(*v)->used && k < 0)
		return (vect_memset(v, x >= 5.0 ? '1' : '0', 1, 0));
	while (x)
	{
		if ((*v)->used && n == prec)
		{
			n = (*v)->used - 1;
			if (x >= (double)10.0/2.0)
			{
				while (((char *)(*v)->data)[n] == '9')
					((char *)(*v)->data)[n--] = '0';
				((char *)(*v)->data)[n == (size_t)-1 ? 0 : n]++;
			}
			return (1);
		}
		if (!(vect_memset(v, (int)x + '0', 1, (*v)->used) && ++n))
			return (0);
		x = (x - (int)x) * 10;
	}
	return (n >= prec ? 1 : vect_memset(v, '0', prec - n, (*v)->used));
}

int					fp_digits
	(t_vect **v, t_parse_result *p, double x, int *k)
{
	if (!(*v || (*v = ft_memalloc(sizeof(**v)))))
		return (0);
	if (!fp_whole(v, &x, k, p->ctxt.prec))
		return (0);
	if (*k > 0 && (*k)++)
		p->ctxt.prec += *k;
	if (*k < -1)
		p->ctxt.prec--;
	if (!p->ctxt.prec)
		p->ctxt.prec++;
	if (!fp_frac(v, x, *k, p->ctxt.prec))
		return (0);
	return (1);
}

int					fp_isfinite
	(t_vect **v, double x, int upper)
{
	unsigned long	cmp;
	int				m;

	cmp = (*(unsigned long *)&x);
	m = cmp & 0xffffffffffffffff;
	cmp >>= 52;
	if ((cmp & 0x7ff) == 0x7ff)
		return (m
		? vect_pushstr(v, upper ? "NAN" : "nan", *v ? (*v)->used : 0) ? 1 : -1
		: vect_pushstr(v, upper ? "INF" : "inf", *v ? (*v)->used : 0) ? 1 : -1
		);
	return (0);
}
