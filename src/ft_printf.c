/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/18 14:28:48 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <unistd.h>

static int					print_result
	(t_vect **builder)
{
	size_t					len;
	t_vect					*w;

	if (!*builder)
		return (0);
	w = *builder;
	write(1, w->data, w->used);
	len = w->used;
	vect_del(builder);
	return (len);
}

int							ft_printf
	(const char *format, ...)
{
	static t_printf_conf	*conf = NULL;
	va_list					ap;
	char					*fmt;
	size_t					len;
	t_vect					*v;
	t_vect					*builder;

	fmt = (char *)format;
	va_start(ap, format);
	builder = NULL;
	v = NULL;
	if (!conf)
		conf = init_conf();
	while (eval_fmt(&fmt, &ap, &v, conf))
	{
		if (!vect_add(&builder, v->data, v->used))
			return (0);
		v->used = 0;
	}
	va_end(ap);
	len = print_result(&builder);
	if (v)
		vect_del(&v);
	bst_delall(&conf->attrs);
	bst_delall(&conf->convs);
	bst_delall(&conf->l_modifs);
	ft_memdel((void **)&conf);
	return (len);
}
