/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:21:24 by dromansk          #+#    #+#             */
/*   Updated: 2019/02/22 01:22:22 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

/*
** not perfect but Imma do either 30 width or longest name plus 2
*/

/*void	print_cols(t_direct **columns, int len, int extra)
{
	int			i;
	int			width;

	i = -1;
	while (columns[++i])
	{
		if (columns[i])
		{
			width = columns[i + 1] ? len : extra;
			print_type(columns[i], width);
			columns[i] = columns[i]->next;
		}
		if (!columns[i + 1])
		{
			ft_putchar('\n');
			if (columns[0])
				i = -1;
			else
				return ;
		}
	}
}

t_direct	*dir_split(t_direct **dir, int len)
{
	t_direct	*curr;
	t_direct	*tmp;
	t_direct	*cut;
	
	curr = *dir;
	tmp = curr;
	while (--len && tmp->next)
		tmp = tmp->next;
	cut = tmp->next;
	tmp->next = NULL;
	*dir = cut;
	return (curr);
}

void		split_dirs(t_direct *d, int cols, int count, int len, int x)
{
	t_direct	**columns;

	int			list_len;
	int			i;

	i = -1;
	list_len = count / cols;
	if (x && will_fit(x, d, list_len + 1))
		list_len++;
	columns = malloc(sizeof(t_direct *) * cols + 1);
	columns[cols] = NULL;
	while (++i < cols)
		columns[i] = dir_split(&d, list_len);
	print_cols(columns, len, x);
}*/

void		print_every_i(t_direct *d, int i, int len)
{
	t_direct		*curr;
	int				count;

	count = 1;
	print_type(d, len);
	curr = d->next;
	while (curr)
	{
		if (!(count % i))
			print_type(curr, len);
		curr = curr->next;
		count++;
	}
}

void		print_cols(t_direct *d, int cols, int size, int len)
{
	int				counter;
	int				i;

	counter = 1;
	i = size / cols;
	if (size % cols)
		i++;
	while (counter <= i)
	{
		print_every_i(d, i, len);
		d = d->next;
		counter++;
		if (counter != i)
			ft_putchar('\n');
	}
}

void		column_count(t_direct *d, int len, int count)
{
	struct winsize	ws;
	int				size;
	int				cols;
//	int				extra;
	
	cols = 1;
	ioctl(1, TIOCGWINSZ, &ws);
	size = ws.ws_col;
//	extra = 0;
	if (size > len)
	{
		cols = size / len;
//		extra = size % len;
	}
	print_cols(d, cols, count, len);
//	split_dirs(d, cols, count, len, extra);
}

void		print_col(t_direct *d)
{
	t_direct	*start;
	int			len;
	int			cmp;
	int			count;
	len = 16;
	count = 0;
	start = d;
	while (d)
	{
		count++;
		cmp = ft_strlen(d->name);
		if (len == 16)
		{
			len = cmp > len ? 30 : len;
		}
		else
			len = cmp > len ? cmp : len;
		d = d->next;
	}
	column_count(start, len, count);
}