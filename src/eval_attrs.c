/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_attrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:13:57 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 23:26:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static void	sharp_attr
	(t_conv_spec *self, t_vect *builder, void *x)
{
	char	s[2];
	t_list	*l;
	size_t	len;

	if (!x)
		return ;
	ft_bzero(s, 2);
	if (self->name == 'o')
		*s = '0';
	else if (self->name == 'x')
		ft_strcpy(s, "0x");
	else if (self->name == 'X')
		ft_strcpy(s, "0X");
	else
		return ;
	len = ft_strlen(s);
	if (!(l = ft_lstnew(s, len)))
		p_exit(PRINTF_ERR_MALLOC, " in function sharp_attr");
	ft_lstadd((t_list **)&builder->content, l);
	builder->size += len;
}

void		eval_attrs
	(t_conv_spec *self, t_vect *builder, t_attrs attrs, void *x)
{
	char	sign;
	t_list	*l;

	if ((1 << SHARP_OFFSET) & attrs)
		sharp_attr(self, builder, x);
	if (!self->sign)
		return ;
	if (self->sign >> 1)
		sign = '-';
	else if ((1 << PLUS_OFFSET) & attrs)
		sign = '+';
	else if ((1 << SPACE_OFFSET) & attrs)
		sign = ' ';
	else
		return ;
	if (!(l = ft_lstnew(NULL, 1)))
		p_exit(PRINTF_ERR_MALLOC, " in function eval_attrs");
	(*(char *)l->content) = sign;
	ft_lstadd((t_list **)&builder->content, l);
	builder->size++;
}
