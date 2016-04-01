/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 22:42:10 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static unsigned long	get_mask
	(size_t size)
{
	unsigned long		mask;
	size_t				i;

	i = 0;
	mask = 0;
	while (i < size * 8)
		mask |= (unsigned long)1 << i++;
	return (mask);
}

static unsigned long	abs_value
	(t_conv_spec *self, void *x)
{
	unsigned long		ret;
	unsigned long		mask;

	ret = (unsigned long)x;
	mask = get_mask(self->size);
	if (self->sign & (ret >> (8 * self->size - 1)))
	{
		ret = mask & (~ ret) + 1;
		self->sign += 2;
	}
	return (ret);
}

t_vect					*i_conv
	(t_conv_spec *self, void *x)
{
	char				*nb;
	t_vect				*ret;
	size_t				base;
	unsigned long		y;

	if (!(ret = ft_memalloc(sizeof(*ret))))
		p_exit(PRINTF_ERR_MALLOC, " in integer conversion");
	base = ft_strlen(alphabets[self->base]);
	y = abs_value(self, x);
	ret->size = digits_nb((void *)y, base);
	if (!(nb = malloc(ret->size)))
		p_exit(PRINTF_ERR_MALLOC, " in integer conversion");
	nb += ret->size;
	while (y >= base)
	{
		*--nb = *(alphabets[self->base] + y % base);
		y /= base;
	}
	*--nb = *(alphabets[self->base] + y);
	ret->content = nb;
	return (ret);
}
