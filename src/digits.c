/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 11:27:23 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/14 18:13:19 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>

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
