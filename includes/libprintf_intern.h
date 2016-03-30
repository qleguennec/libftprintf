/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:40 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/30 20:38:14 by qle-guen         ###   ########.fr       */
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


int					ft_printf(const char *format, ...);
void				init(void);
char				*eval_arg(char **fmt, char *sep, void *arg);
void				p_exit(char *s1, char *s2);
int					cmp(void *a, void *b);

#endif
