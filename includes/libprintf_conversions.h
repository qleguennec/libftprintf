/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_conversions.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:30:55 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/08 13:54:53 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_CONVERSIONS_H
# define LIBPRINTF_CONVERSIONS_H

#include <libprintf_alphabets.h>
#include <libprintf_l_modifiers.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>
#include <libft.h>

typedef uintmax_t	t_arg;

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
	t_list			*(* conv_f)(struct s_conv_spec *, t_ctxt_spec *);
	size_t			size;
	unsigned int	base : 3;
	unsigned int	valid_attrs : 5;
}					t_conv_spec;

t_list				*i_conv(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list				*s_conv(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list				*c_conv(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list				*wc_conv(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list				*wstr_conv(t_conv_spec *self, t_ctxt_spec *ctxt);
t_list				*percent(t_conv_spec *self, t_ctxt_spec *ctxt);

static t_conv_spec	convs_arr[] =
{
	{"d" , "0"      , &i_conv  , sizeof(int)      , BASE10    , 30} ,
	{"u" , "0"      , &i_conv  , sizeof(int)      , BASE10    , 3}  ,
	{"i" , "0"      , &i_conv  , sizeof(int)      , BASE10    , 3}  ,
	{"o" , "0"      , &i_conv  , sizeof(int)      , BASE8     , 3}  ,
	{"x" , "0"      , &i_conv  , sizeof(int)      , BASE16LOW , 3}  ,
	{"X" , "0"      , &i_conv  , sizeof(int)      , BASE16UP  , 3}  ,
	{"D" , "0"      , &i_conv  , sizeof(long int) , BASE10    , 30} ,
	{"O" , "0"      , &i_conv  , sizeof(long int) , BASE8     , 3}  ,
	{"U" , "0"      , &i_conv  , sizeof(int)      , BASE10    , 3}  ,
	{"p" , "(nil)"  , &i_conv  , 0                , BASE16LOW , 1}  ,
	{"c" , ""       , &c_conv  , 1                , 0         , 0}  ,
	{"C" , ""       , &c_conv  , 2                , 0         , 0}  ,
	{"s" , "(null)" , &s_conv  , 1                , 0         , 0}  ,
	{"S" , "(null)" , &s_conv  , 2                , 0         , 0}  ,
	{"%" , ""       , &percent , 0                , 0         , 0}  ,
};

#endif
