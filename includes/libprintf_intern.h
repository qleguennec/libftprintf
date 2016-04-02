/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:40 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/02 15:46:46 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_INTERN_H
# define LIBPRINTF_INTERN_H

#include <libft.h>
#include <libbst.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include <libprintf_errors.h>
#include <libprintf_conversions.h>
#include <libprintf_attributes.h>

typedef struct			s_printf_conf
{
	t_bst_tree			*convs;
	t_bst_tree			*attrs;
}						t_printf_conf;

static t_printf_conf	*conf = NULL;

int						ft_printf(const char *format, ...);
t_printf_conf			*init_conf(void);
t_list					*parse_fmt
	(char **fmt, void ***arg, t_printf_conf *conf);
void					p_exit(char *s1, char *s2);
int						cmp(void *a, void *b);
size_t					digits_nb(void *x, int base);

#endif
