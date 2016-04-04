/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   null_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:58:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/04 14:59:13 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

t_list	*null_case
	(t_conv_spec *self)
{
	return (ft_lstnew(self->null_case, ft_strlen(self->null_case)));
}
