/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/02 16:57:42 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

static void		copy_args
	(va_list ap, void ***args, size_t n_args)
{
	size_t		i;

	i = 0;
	*args = malloc(n_args * sizeof(**args));
	while (i < n_args)
		(*args)[i++] = va_arg(ap, void *);
}

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
			p_exit(PRINTF_ERR_MALLOC, " in function print_result");
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
	void		**args;
	t_list		*result;
	t_list		*builder;

	fmt = (char *)format;
	n_args = 0;
	while ((fmt = ft_strchr(fmt, '%')) && fmt++)
		n_args++;
	va_start(ap, format);
	copy_args(ap, &args, n_args);
	va_end(ap);
	fmt = (char *)format;
	builder = NULL;
	if (!conf)
		conf = init_conf();
	while ((result = parse_fmt(&fmt, &args, conf)))
		ft_lstadd(&builder, result);
	free(args - n_args);
	return (print_result(&builder));
}
