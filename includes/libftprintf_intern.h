/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:40 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/24 14:16:15 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_INTERN_H
# define LIBFTPRINTF_INTERN_H

# define BASE2		0
# define BASE8		1
# define BASE10		2
# define BASE16LOW	3
# define BASE16UP	4

# define ATTR(x)	(p->ctxt.attrs & x)
# define SHARP		(1 << 0)
# define ZERO		(1 << 1)
# define MINUS		(1 << 2)
# define SPACE		(1 << 3)
# define PLUS		(1 << 4)
# define APO		(1 << 5)

# include <libft.h>
# include <libftprintf.h>
# include <stdio.h>
# include <libvect.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>

static char				*g_alphabets[] =
{
	"01",
	"01234567",
	"0123456789",
	"0123456789abcdef",
	"0123456789ABCDEF",
};

typedef struct			s_l_modif_spec
{
	char				name[3];
	size_t				size;
}						t_l_modif_spec;

static t_l_modif_spec	g_l_modifs_arr[] =
{
	{"h", sizeof(short)},
	{"hh", sizeof(char)},
	{"j", sizeof(intmax_t)},
	{"l", sizeof(long)},
	{"ll", sizeof(long long)},
	{"t", sizeof(ptrdiff_t)},
	{"z", sizeof(size_t)},
};

typedef struct			s_attr_spec
{
	char				name[3];
	unsigned int		mask : 6;
}						t_attr_spec;

static t_attr_spec		g_attrs_arr[] =
{
	{" ", SPACE},
	{"#", SHARP},
	{"'", APO},
	{"+", PLUS},
	{"-", MINUS},
	{"0", ZERO},
};

typedef union			u_arg
{
	size_t				g;
	double				d;
}						t_arg;
struct s_conv_spec;
struct s_ctxt_spec;
struct s_parse_result;

typedef struct			s_ctxt_spec
{
	unsigned int		attrs : 6;
	unsigned int		neg : 1;
	size_t				width;
	unsigned int		prec_given : 1;
	size_t				prec;
	t_l_modif_spec		*l_modif;
	t_arg				arg;
}						t_ctxt_spec;

typedef struct			s_conv_spec
{
	char				name[3];
	int					(* conv_f)(struct s_parse_result *, t_vect **);
	size_t				size;
	unsigned int		base : 3;
	unsigned int		valid_attrs : 5;
	unsigned int		ismodif_length : 1;
}						t_conv_spec;

typedef struct			s_parse_result
{
	t_conv_spec			*conv;
	t_ctxt_spec			ctxt;
}						t_parse_result;

int						i_conv(t_parse_result *p, t_vect **v);
int						f_conv(t_parse_result *p, t_vect **v);
int						e_conv(t_parse_result *p, t_vect **v);
int						g_conv(t_parse_result *p, t_vect **v);
int						p_conv(t_parse_result *p, t_vect **v);
int						s_conv(t_parse_result *p, t_vect **v);
int						c_conv(t_parse_result *p, t_vect **v);
int						wc_conv(t_parse_result *p, t_vect **v);
int						ws_conv(t_parse_result *p, t_vect **v);
int						percent(t_parse_result *p, t_vect **v);

static t_conv_spec	g_convs_arr[] =
{
	{"%", &percent, 0, 0, 6, 0},
	{"C", &wc_conv, 2, 0, 6, 0},
	{"D", &i_conv, sizeof(long), BASE10, 30, 0},
	{"O", &i_conv, sizeof(long), BASE8, 3, 0},
	{"S", &ws_conv, 2, 0, 6, 0},
	{"U", &i_conv, sizeof(long), BASE10, 3, 0},
	{"X", &i_conv, sizeof(int), BASE16UP, 3, 1},
	{"b", &i_conv, sizeof(int), BASE2, 30, 1},
	{"c", &c_conv, 2, 0, 6, 1},
	{"d", &i_conv, sizeof(int), BASE10, 30, 1},
	{"i", &i_conv, sizeof(int), BASE10, 30, 1},
	{"o", &i_conv, sizeof(int), BASE8, 7, 1},
	{"p", &p_conv, 2, BASE16LOW, 6, 0},
	{"s", &s_conv, 2, 0, 6, 1},
	{"u", &i_conv, sizeof(int), BASE10, 7, 1},
	{"x", &i_conv, sizeof(int), BASE16LOW, 7, 1},
};

int						eval_post(t_parse_result *p, t_vect **v);
int						eval_fmt(char **fmt, va_list ap, t_vect **v);
size_t					digits_nb(size_t x, int base);
unsigned int			parse_attrs(char **fmt);
size_t					parse_num(char **fmt, va_list ap);
t_conv_spec				*parse_conv(char **fmt);
t_l_modif_spec			*parse_l_modif(char **fmt);
t_vect					*get_result(const char *fmt, va_list ap);

#endif
