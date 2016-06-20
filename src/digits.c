/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:27:23 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/20 19:07:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <float.h>
#include <stdio.h>

size_t				digits_nb
	(size_t x, int base)
{
	size_t			digits;

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

t_vect				*fp_whole
	(double *x)
{
	int				a;
	int				i;
	t_vect			*v;

	v = NULL;
	if (*x < 1.0)
		return (vect_addstr(&v, "0") ? v : NULL);
	i = 0;
	while (*x >= 1.0)
	{
		*x /= 10;
		i++;
	}
	*x *= 10;
	if (!((v = ft_memalloc(sizeof(*v))) && vect_req(v, i)))
		return (NULL);
	while (i)
	{
		a = (int)*x;
		*x = (*x - a) * 10;
		vect_memset(&v, a + '0', 1, v->used);
		i--;
	}
	*x /= 10;
	return (v);
}

t_vect			*fp_frac
	(double x, size_t width)
{
	int			a;
	t_vect		*v;

	if (!(v = ft_memalloc(sizeof(*v))))
		return (NULL);
	if (!width)
		return (v);
	x *= 10;
	a = (int)x;
	while (x && width)
	{
		vect_memset(&v, a + '0', 1, v ? v->used : 0);
		x -= a;
		x *= 10;
		a = (int)x;
		width--;
	}
	vect_memset(&v, '0', width, v->used);
	return (v);
}
