/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_l_modifiers.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 18:31:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/09 13:54:10 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_L_MODIFIERS_H
# define LIBPRINTF_L_MODIFIERS_H

#include <stdint.h>
#include <stdlib.h>

typedef struct			s_l_modif_spec
{
	char				name[3];
	size_t				size;
}						t_l_modif_spec;

static t_l_modif_spec	l_modifs_arr[] =
{
	{"hh" , sizeof(char)}      ,
	{"h"  , sizeof(short)}     ,
	{"l"  , sizeof(long)}      ,
	{"ll" , sizeof(long long)} ,
	{"j"  , sizeof(intmax_t)}  ,
	{"t"  , sizeof(ptrdiff_t)} ,
	{"z"  , sizeof(size_t)}    ,
};

#endif
