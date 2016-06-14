/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 18:27:40 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/14 18:15:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_INTERN_H
# define LIBFTPRINTF_INTERN_H

#define BASE2		0
#define BASE8		1
#define BASE10		2
#define BASE16LOW	3
#define BASE16UP	4

#define SHARP_MASK	(1 << 0)
#define ZERO_MASK	(1 << 1)
#define MINUS_MASK	(1 << 2)
#define SPACE_MASK	(1 << 3)
#define PLUS_MASK	(1 << 4)

# include <libft.h>
# include <libbst.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>

typedef struct			s_printf_conf
{
	t_bst_tree			*convs;
	t_bst_tree			*attrs;
	t_bst_tree			*l_modifs;
}						t_printf_conf;

static t_printf_conf	*g_conf = NULL;

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
	{"hh", sizeof(char)},
	{"h", sizeof(short)},
	{"l", sizeof(long)},
	{"ll", sizeof(long long)},
	{"j", sizeof(intmax_t)},
	{"t", sizeof(ptrdiff_t)},
	{"z", sizeof(size_t)},
};

typedef struct			s_attr_spec
{
	char				name[3];
	unsigned int		mask : 5;
}						t_attr_spec;

static t_attr_spec		g_attrs_arr[] =
{
	{"#", SHARP_MASK},
	{"0", ZERO_MASK},
	{"-", MINUS_MASK},
	{" ", SPACE_MASK},
	{"+", PLUS_MASK},
};

typedef size_t			t_arg;
struct s_conv_spec;
struct s_ctxt_spec;
struct s_parse_result;

typedef struct			s_ctxt_spec
{
	unsigned int		attrs : 5;
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
	t_list				*(* conv_f)(struct s_parse_result *);
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

t_list					*i_conv(t_parse_result *p);
t_list					*p_conv(t_parse_result *p);
t_list					*s_conv(t_parse_result *p);
t_list					*c_conv(t_parse_result *p);
t_list					*wc_conv(t_parse_result *p);
t_list					*ws_conv(t_parse_result *p);
t_list					*percent(t_parse_result *p);

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

t_printf_conf			*init_conf(void);
t_list					*eval_attrs_post(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list					*eval_fmt(char **fmt, va_list *ap, t_printf_conf *conf);
void					p_exit(char *s1, char *s2);
size_t					digits_nb(t_arg x, int base);
int						cmp(void *a, void *b);
unsigned int			parse_attrs(char **fmt, t_printf_conf *conf);
size_t					parse_num(char **fmt, va_list *ap);
t_conv_spec				*parse_conv(char **fmt, t_printf_conf *conf);
t_l_modif_spec			*parse_l_modif(char **fmt, t_printf_conf *conf);
int						handle_wildcard(char **fmt, va_list *cpy);

#endif
