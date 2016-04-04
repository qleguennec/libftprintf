/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:27:23 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/04 14:40:42 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

size_t				digits_nb
	(t_arg x, int base)
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
