/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/08 20:14:32 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf_intern.h>
#include <unistd.h>

static int		print_result
	(t_list **builder)
{
	size_t		len;

	if (!*builder)
		return (0);
	if (!(ft_lstrevbuild(*builder)))
		return (-1);
	len = (*builder)->content_size;
	write(1, (*builder)->content, len);
	ft_lstdel(builder, &ft_delete);
	bst_delete(g_conf->attrs);
	bst_delete(g_conf->convs);
	bst_delete(g_conf->l_modifs);
	ft_memdel((void **)&g_conf);
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
	if (!g_conf)
		g_conf = init_conf();
	while ((result = eval_fmt(&fmt, &ap, g_conf)))
		ft_lstadd(&builder, result);
	va_end(ap);
	return (print_result(&builder));
}
