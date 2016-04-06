/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wc_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 11:36:05 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 16:21:44 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

size_t		insert_wc(char *s, wchar_t wc)
{
	size_t	len;
	size_t	i;
	wchar_t	mask;

	if (wc < 0x80 && ((*s = wc) || 1))
		return (1);
	len = 0;
	mask = 0;
	while ((unsigned)mask < (unsigned)wc)
		mask |= (1 << len++);
	i = 1;
	mask = 0;
	len /= sizeof(wc);
	while (i <= len)
		mask |= 1 << (6 + len - i++);
	i = 0;
	while (i < len)
	{
		s[i] = mask | (((wc >> 6 * (len - i - 1)) & 0x3f));
		mask = 0x80;
		i++;
	}
	return (len);
}

t_list		*wc_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	char	result[sizeof(wchar_t)];
	size_t	len;

	(void)self;
	len = insert_wc(result, (wchar_t)ctxt->arg);
	return (ft_lstnew(result, len));
}

t_list		*wstr_conv
	(t_conv_spec *self, t_ctxt_spec *ctxt)
{
	char	*result;
	wchar_t	*arg;
	size_t	len;
	t_list	*ret;

	(void)self;
	arg = (wchar_t *)ctxt->arg;
	if (!(result = malloc(ft_wstrlen(arg) * sizeof(wchar_t))))
		return (NULL);
	len = 0;
	while (*arg)
	{
		len += insert_wc(result + len, *arg);
		arg++;
	}
	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->content = result;
	ret->content_size = len;
	return (ret);
}
