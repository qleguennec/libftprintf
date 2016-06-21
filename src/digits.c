/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:27:23 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/21 17:41:20 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

size_t					digits_nb
	(size_t x, int base)
{
	size_t				digits;

	if (!x)
		return (1);
	digits = 0;
	while (x)
	{
		x /= base;
		digits++;
	}
	return (digits);
}

static int				fp_whole
	(t_vect **v, double *x)
{
	int					a;
	size_t				i;

	if (*x < 1.0)
		return (vect_addstr(v, "0"));
	i = 0;
	while (*x >= 1.0)
	{
		*x /= 10;
		i++;
	}
	*x *= 10;
	if (!vect_req(v, i))
		return (0);
	while (i)
	{
		a = (int)*x;
		*x = (*x - a) * 10;
		vect_memset(v, a + '0', 1, (*v)->used);
		i--;
	}
	*x /= 10;
	return (1);
}

static int			fp_frac
	(t_vect **v, double x, size_t prec)
{
	int				a;

	x *= 10;
	a = (int)x;
	while (prec)
	{
		if (!vect_memset(v, a + '0', 1, v ? (*v)->used : 0))
			return (0);
		x -= a;
		x *= 10;
		a = (int)x;
		prec--;
	}
	return (vect_memset(v, '0', prec, v ? (*v)->used : 0) ? 1 : 0);
}

int					fp_digits
	(t_vect **v, double x, size_t prec, size_t max_w)
{
	int				ret;

	if (!fp_whole(v, &x))
		return (0);
	ret = (int)(*v)->used;
	if (max_w)
		prec -= ret - max_w;
	if (!fp_frac(v, x, prec))
		return (0);
	return (ret);
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
