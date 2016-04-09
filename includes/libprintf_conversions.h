/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 14:15:54 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_CONVERSIONS_H
# define LIBPRINTF_CONVERSIONS_H

#include <libprintf_alphabets.h>
#include <libprintf_l_modifiers.h>
#include <libprintf_intern.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <libft.h>

typedef size_t		t_arg;
struct				s_conv_spec;
struct				s_ctxt_spec;
struct				s_parse_result;

typedef struct		s_ctxt_spec
{
	unsigned int	attrs : 5;
	unsigned int	neg : 1;
	size_t			width;
	size_t			prec;
	t_l_modif_spec	*l_modif;
	t_arg			arg;
}					t_ctxt_spec;

typedef struct		s_conv_spec
{
	char			name[3];
	char			null_case[10];
	t_list			*(* conv_f)(struct s_parse_result *);
	size_t			size;
	unsigned int	base : 3;
	unsigned int	valid_attrs : 5;
	unsigned int	ismodif_length;
}					t_conv_spec;

typedef struct		s_parse_result
{
	t_conv_spec		*conv;
	t_ctxt_spec		ctxt;
}					t_parse_result;

t_list				*i_conv(t_parse_result *p);
t_list				*s_conv(t_parse_result *p);
t_list				*c_conv(t_parse_result *p);
t_list				*wc_conv(t_parse_result *p);
t_list				*ws_conv(t_parse_result *p);
t_list				*percent(t_parse_result *p);

static t_conv_spec	convs_arr[] =
{
	{"d" , "0"      , &i_conv  , sizeof(int)    , BASE10    , 30 , 1} ,
	{"u" , "0"      , &i_conv  , sizeof(int)    , BASE10    , 3  , 1} ,
	{"i" , "0"      , &i_conv  , sizeof(int)    , BASE10    , 30 , 1} ,
	{"o" , "0"      , &i_conv  , sizeof(int)    , BASE8     , 3  , 1} ,
	{"x" , "0"      , &i_conv  , sizeof(int)    , BASE16LOW , 3  , 1} ,
	{"X" , "0"      , &i_conv  , sizeof(int)    , BASE16UP  , 3  , 1} ,
	{"D" , "0"      , &i_conv  , sizeof(long)   , BASE10    , 30 , 0} ,
	{"O" , "0"      , &i_conv  , sizeof(long)   , BASE8     , 3  , 0} ,
	{"U" , "0"      , &i_conv  , sizeof(long)   , BASE10    , 3  , 0} ,
	{"p" , "0x0"    , &i_conv  , sizeof(void *) , BASE16LOW , 4  , 0} ,
	{"c" , ""       , &c_conv  , 1              , 0         , 0  , 1} ,
	{"C" , ""       , &wc_conv , 1              , 0         , 0  , 0} ,
	{"s" , "(null)" , &s_conv  , 1              , 0         , 0  , 1} ,
	{"S" , "(null)" , &ws_conv , 1              , 0         , 0  , 0} ,
	{"%" , ""       , &percent , 0              , 0         , 0  , 1} ,
};

#endif
