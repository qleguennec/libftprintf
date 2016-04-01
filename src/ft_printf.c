/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/01 18:57:19 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

int			ft_printf
	(const char *format, ...)
{
	va_list	l;
	char	*sep;
	char	*fmt;
	t_vect	*result;
	void	*arg;

	if (!conf)
		conf = init_conf();
	fmt = (char *)format;
	va_start(l, format);
	while (*fmt)
	{
		if (!(sep = ft_strchr(fmt, '%')))
		{
			ft_putstr(fmt);
			break;
		}
		write(1, fmt, sep - fmt);
		arg = va_arg(l, void*);
		result = eval_arg(conf, &fmt, sep + 1, arg);
		write(1, result->content, result->size);
		free(result->content);
		free(result);
	}
	va_end(l);
	return (1);
}
