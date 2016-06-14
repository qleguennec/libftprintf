/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf_l_modifiers.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 18:31:21 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/09 08:30:35 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_L_MODIFIERS_H
# define LIBFTPRINTF_L_MODIFIERS_H

# include <stdint.h>
# include <stdlib.h>
# include <stddef.h>

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

#endif
