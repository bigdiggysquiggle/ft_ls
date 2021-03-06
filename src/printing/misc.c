/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:59:06 by dromansk          #+#    #+#             */
/*   Updated: 2019/12/19 17:30:25 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

char	*suffix_join(char *size, char *units, int unit)
{
	char	*tmp;
	char	*res;

	tmp = ft_strndup(units + unit, unit ? 1 : 0);
	res = ft_strjoin(size, tmp);
	free(size);
	free(tmp);
	return (res);
}

char	*size_str(long size, short flags)
{
	double	perc;
	int		unit;
	char	*units;

	unit = 0;
	units = "BKMGTP";
	if (!(flags & h))
		return (ft_ltoa(size));
	perc = (double)size;
	while (units[unit] && size > 1024)
	{
		unit++;
		size /= 1024;
		perc /= (double)1024;
	}
	return (suffix_join(ft_ftoa(perc, 1), units, unit));
}

void	print_list(t_direct *d)
{
	t_rex	*recs;

	recs = NULL;
	if (!d)
		return ;
	if (d->flags & l || d->flags & g)
		get_blocks(d);
	if (d->flags & R)
		recs = new_rex(NULL);
	while (d)
	{
		print_type(d, 1);
		ft_putchar('\n');
		if (d->flags & R && !ft_strequ(d->name, ".") &&
				!ft_strequ(d->name, "..") && is_type(*d->stats, S_IFDIR))
			add_rex(d, &recs);
		d = d->next;
	}
	check_recursion(&recs);
	del_rex(recs);
}

void	print_one(char *file, short flags)
{
	t_direct	*ffile;

	ffile = new_direct(file, "", flags);
	print_list(ffile);
	free(ffile);
}
