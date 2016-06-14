/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/08 19:57:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_CONVERSIONS_H
# define LIBFTPRINTF_CONVERSIONS_H

# include <libftprintf_intern.h>
# include <libftprintf_l_modifiers.h>
# include <libftprintf_alphabets.h>
# include <stdlib.h>

typedef size_t		t_arg;
struct s_conv_spec;
struct s_ctxt_spec;
struct s_parse_result;

typedef struct		s_ctxt_spec
{
	unsigned int	attrs : 5;
	unsigned int	neg : 1;
	size_t			width;
	unsigned int	prec_given : 1;
	size_t			prec;
	t_l_modif_spec	*l_modif;
	t_arg			arg;
}					t_ctxt_spec;

typedef struct		s_conv_spec
{
	char			name[3];
	t_list			*(* conv_f)(struct s_parse_result *);
	size_t			size;
	unsigned int	base : 3;
	unsigned int	valid_attrs : 5;
	unsigned int	ismodif_length : 1;
}					t_conv_spec;

typedef struct		s_parse_result
{
	t_conv_spec		*conv;
	t_ctxt_spec		ctxt;
}					t_parse_result;

t_list				*i_conv(t_parse_result *p);
t_list				*p_conv(t_parse_result *p);
t_list				*s_conv(t_parse_result *p);
t_list				*c_conv(t_parse_result *p);
t_list				*wc_conv(t_parse_result *p);
t_list				*ws_conv(t_parse_result *p);
t_list				*percent(t_parse_result *p);

static t_conv_spec	g_convs_arr[] =
{
	{"d", &i_conv, sizeof(int), BASE10, 30, 1},
	{"u", &i_conv, sizeof(int), BASE10, 7, 1},
	{"i", &i_conv, sizeof(int), BASE10, 30, 1},
	{"o", &i_conv, sizeof(int), BASE8, 7, 1},
	{"x", &i_conv, sizeof(int), BASE16LOW, 7, 1},
	{"X", &i_conv, sizeof(int), BASE16UP, 3, 1},
	{"D", &i_conv, sizeof(long), BASE10, 30, 0},
	{"O", &i_conv, sizeof(long), BASE8, 3, 0},
	{"U", &i_conv, sizeof(long), BASE10, 3, 0},
	{"p", &p_conv, 1, BASE16LOW, 6, 0},
	{"c", &c_conv, 1, 0, 6, 1},
	{"C", &wc_conv, 1, 0, 6, 0},
	{"s", &s_conv, 1, 0, 6, 1},
	{"S", &ws_conv, 1, 0, 6, 0},
	{"%", &percent, 0, 0, 6, 0},
};

#endif
