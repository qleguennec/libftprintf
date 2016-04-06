/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:40 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/06 20:38:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_INTERN_H
# define LIBPRINTF_INTERN_H

#include <libft.h>
#include <libbst.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include <libprintf_errors.h>
#include <libprintf_conversions.h>
#include <libprintf_attributes.h>
#include <libprintf_l_modifiers.h>

typedef struct			s_printf_conf
{
	t_bst_tree			*convs;
	t_bst_tree			*attrs;
	t_bst_tree			*l_modifs;
}						t_printf_conf;

typedef struct			s_parse_result
{
	t_conv_spec			*conv;
	t_ctxt_spec			ctxt;
}						t_parse_result;

static t_printf_conf	*conf = NULL;

int						ft_printf(const char *format, ...);
t_printf_conf			*init_conf(void);
t_list					*eval_attrs
	(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list					*eval_fmt
	(char **fmt, va_list ap, t_printf_conf *conf);
t_list					*null_case(t_conv_spec *self);
void					p_exit(char *s1, char *s2);
size_t					digits_nb(t_arg x, int base);
int						cmp(void *a, void *b);
unsigned int			parse_attrs(char **fmt, t_printf_conf *conf);
size_t					parse_width(char **fmt);
size_t					parse_prec(char **fmt);
t_conv_spec				*parse_conv(char **fmt, t_printf_conf *conf);
size_t					parse_l_modif(char **fmt, t_printf_conf *conf);

#endif
