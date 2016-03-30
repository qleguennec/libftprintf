/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 18:42:34 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

int			ft_printf
	(const char *format, ...)
{
	va_list	l;
	char	*sep;
	char	*fmt;
	char	*result;
	void	*arg;

	init();
	fmt = (char *)format;
	va_start(l, format);
	while (*fmt)
	{
		if (!(sep = ft_strchr(fmt, '%')))
		{
			ft_putstr(fmt);
			break;
		}
		write(1, fmt, sep - format);
		arg = va_arg(l, void*);
		result = eval_arg(&fmt, sep + 1, arg);
		ft_putstr(result);
		ft_strdel(&result);
	}
	va_end(l);
	return (1);
}
