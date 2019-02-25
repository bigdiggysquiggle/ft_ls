/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstruct.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:12:09 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/21 15:34:42 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSTRUCT_H
# define FSTRUCT_H
# include "lsenums.h"
# include "lstructs.h"

t_ftypes g_ftypes[] =
{
	{'1', 0},
	{'l', l},
	{'R', R},
	{'a', a},
	{'r', r},
	{'t', t},
	{'g', g},
	{'f', f + a},
	{'G', G},
	{'o', o + l},
	{'A', A + a},
	{'d', d},
	{'u', u}
};

/*
**	{'u', u},
**	{'F', F}
*/

#endif
