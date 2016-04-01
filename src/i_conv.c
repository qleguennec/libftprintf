/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:19:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 18:39:35 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static unsigned long	get_mask
	(size_t size)
{
	unsigned long		mask;
	size_t				i;

	i = 0;
	ft_bzero(&mask, sizeof(mask));
	while (i < size * 8)
	{
		mask |= (unsigned long)1 << i++;
	}
	return (mask);
}

t_vect					*i_conv
	(void *x, t_conv_spec *self)
{
	char				*nb;
	t_vect				*ret;
	size_t				base;
	unsigned long		mask;
	unsigned long		y;

	if (!(ret = ft_memalloc(sizeof(*ret))))
		p_exit(PRINTF_ERR_MALLOC, " in integer conversion");
	base = ft_strlen(alphabets[self->base]);
	mask = get_mask(self->size);
	y = (unsigned long)x;
	if ((self->sign &= (y >> (8 * self->size - 1))))
		y = mask & (~ y) + 1;
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
