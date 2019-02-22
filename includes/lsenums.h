/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsenums.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:02:51 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/21 22:22:44 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSENUMS_H
# define LSENUMS_H

typedef enum e_lsflag	t_lsflag;

enum	e_lsflag
{
	l = 2, R = 4, a = 8, r = 16, t = 32, g = 64, f = 128, G = 256, o = 512
};

#endif
