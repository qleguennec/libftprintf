/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:27:23 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 18:40:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

size_t				digits_nb
	(void* x, int base)
{
	unsigned long	y;
	size_t			digits;

	if (!x)
		return (1);
	y = (unsigned long)x;
	digits = 0;
	while (y)
	{
		y /= base;
		digits++;
	}
	return (digits);
}
