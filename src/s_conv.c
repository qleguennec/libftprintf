/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 02:11:07 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/03 20:17:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list			*s_conv
	(t_conv_spec *self, void *x, size_t precision)
{
	t_list		*ret;
	size_t		len;

	(void)self;
	(void)precision;
	len = (x ? ft_strlen(x) : 7);
	if (!(ret = ft_lstnew(NULL, len)))
		return (NULL);
	if (x)
		ft_memcpy(ret->content, x, len);
	else
		ft_strcpy(ret->content, "(null)");
	return (ret);
}
