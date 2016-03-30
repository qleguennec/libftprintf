/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:42:51 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 20:44:33 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libprintf_intern.h>

char				*eval_arg
	(char **fmt, char *sep, void *arg)
{
	t_attr_spec		*as;
	t_conv_spec		*cs;
	t_attrs			*attrs;
	char			letter[3];

	ft_bzero(letter, 3);
	if (!(attrs = ft_memalloc(sizeof(*attrs))))
		p_exit(PRINTF_ERR_MALLOC, " in function eval_arg");
	while ((*letter = *sep)
		&& (as = (t_attr_spec *)bst_search(attributes, letter, &cmp)))
	{
		as->attr_f(attrs);
		sep++;
	}
	if (!(cs = (t_conv_spec *)bst_search(conversions, letter, &cmp)))
		p_exit(PRINTF_ERR_CONV, letter);
	cs->conv_f(arg);
	*fmt = sep;
	return (NULL);
}
