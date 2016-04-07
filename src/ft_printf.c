/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/07 18:31:11 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static int		print_result
	(t_list **builder)
{
	char		*s;
	t_list		*l;
	size_t		len;

	l = *builder;
	len = 0;
	while (l)
	{
		len += l->content_size;
		l = l->next;
	}
	if (!(s = ft_strnew(len)))
		return (0);
	l = *builder;
	s += len;
	while (l)
	{
		s -= l->content_size;
		ft_memcpy(s, l->content, l->content_size);
		l = l->next;
	}
	ft_lstdel(builder, &ft_delete);
	ft_putstr(s);
	free(s);
	return (len);
}

int				ft_printf
	(const char *format, ...)
{
	va_list		ap;
	size_t		n_args;
	char		*fmt;
	t_list		*result;
	t_list		*builder;

	fmt = (char *)format;
	n_args = 0;
	va_start(ap, format);
	fmt = (char *)format;
	builder = NULL;
	if (!conf)
		conf = init_conf();
	while ((result = eval_fmt(&fmt, ap, conf)))
		ft_lstadd(&builder, result);
	va_end(ap);
	return (print_result(&builder));
}
