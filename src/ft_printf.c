/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/20 14:05:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static int		print_result
	(t_list **builder)
{
	size_t		len;

	if (!(ft_lstrevbuild(*builder)))
		return (-1);
	len = (*builder)->content_size;
	write(1, (*builder)->content, len);
	ft_lstdel(builder, &ft_delete);
	ft_memdel((void **)&conf);
	return (len);
}

int				ft_printf
	(const char *format, ...)
{
	va_list		ap;
	char		*fmt;
	t_list		*result;
	t_list		*builder;

	fmt = (char *)format;
	va_start(ap, format);
	builder = NULL;
	if (!conf)
		conf = init_conf();
	while ((result = eval_fmt(&fmt, &ap, conf)))
		ft_lstadd(&builder, result);
	va_end(ap);
	return (print_result(&builder));
}
