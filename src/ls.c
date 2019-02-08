/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 15:41:57 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/07 16:50:05 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int ac, char **av)
{
	t_direct	*d;
	char		*path;

	if(!new_direct(&d))
		return (0);
	path = ac == 1 ? "./" : av[1];
	d->stream = opendir(path);
	d->direct = readdir(d->stream);
	printf("%s\n", d->direct->d_name);
	closedir(d->stream);
	return (0);
}
