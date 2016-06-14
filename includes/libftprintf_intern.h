/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:40 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/14 13:49:14 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_INTERN_H
# define LIBFTPRINTF_INTERN_H

# include <libft.h>
# include <libbst.h>
# include <stdarg.h>
# include <stdlib.h>
# include <libftprintf_conversions.h>
# include <libftprintf_attributes.h>
# include <libftprintf_l_modifiers.h>

typedef struct			s_printf_conf
{
	t_bst_tree			*convs;
	t_bst_tree			*attrs;
	t_bst_tree			*l_modifs;
}						t_printf_conf;

static t_printf_conf	*g_conf = NULL;

t_printf_conf			*init_conf(void);
t_list					*eval_attrs_post(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list					*eval_fmt(char **fmt, va_list *ap, t_printf_conf *conf);
void					p_exit(char *s1, char *s2);
size_t					digits_nb(t_arg x, int base);
int						cmp(void *a, void *b);
unsigned int			parse_attrs(char **fmt, t_printf_conf *conf);
size_t					parse_width(char **fmt);
size_t					parse_prec(char **fmt);
t_conv_spec				*parse_conv(char **fmt, t_printf_conf *conf);
t_l_modif_spec			*parse_l_modif(char **fmt, t_printf_conf *conf);
int						handle_wildcard(char **fmt, va_list *cpy);

#endif
