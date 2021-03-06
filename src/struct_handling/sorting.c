/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dromansk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:41:16 by dromansk          #+#    #+#             */
/*   Updated: 2019/12/19 18:47:38 by dromansk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include "lsenums.h"

#ifdef __linux__

int		t_is_sorted(t_direct *d1, t_direct *d2)
{
	struct stat	s1;
	struct stat	s2;

	s1 = *d1->stats;
	s2 = *d2->stats;
	if (s1.st_mtim.tv_sec < s2.st_mtim.tv_sec)
		return (t);
	else if (s1.st_mtim.tv_sec == s2.st_mtim.tv_sec)
	{
		if (s1.st_mtim.tv_nsec < s2.st_mtim.tv_nsec)
			return (t);
		else if (s1.st_mtim.tv_nsec == s2.st_mtim.tv_nsec)
			return (is_sorted(d1->name, d2->name) ? t : 0);
	}
	return (0);
}

#else

int		t_is_sorted(t_direct *d1, t_direct *d2)
{
	struct stat	s1;
	struct stat	s2;

	s1 = *d1->stats;
	s2 = *d2->stats;
	if (s1.st_mtimespec.tv_sec < s2.st_mtimespec.tv_sec)
		return (t);
	else if (s1.st_mtimespec.tv_sec == s2.st_mtimespec.tv_sec)
	{
		if (s1.st_mtimespec.tv_nsec < s2.st_mtimespec.tv_nsec)
			return (t);
		else if (s1.st_mtimespec.tv_nsec == s2.st_mtimespec.tv_nsec)
			return (is_sorted(d1->name, d2->name) ? t : 0);
	}
	return (0);
}

#endif

void	f_sort(t_direct **list)
{
	t_direct	*dir;
	t_direct	*last;

	dir = *list;
	last = NULL;
	while (dir->next)
	{
		if (!(ft_strcmp(dir->next->name, ".") &&
					ft_strcmp(dir->next->name, "..")) &&
				!is_sorted(dir->name, dir->next->name))
		{
			if (dir != *list)
				last->next = dir->next;
			else
				*list = dir->next;
			dir_swap(&dir);
			dir = *list;
		}
		else
		{
			last = dir;
			dir = dir->next ? dir->next : dir;
		}
	}
}

void	t_sort(t_direct **list)
{
	t_direct	*dir;
	t_direct	*last;

	dir = *list;
	last = NULL;
	while (!(ft_strcmp(".", dir->name) && ft_strcmp("..", dir->name)))
		dir = dir->next;
	while (dir->next)
	{
		if ((t & dir->flags)
				== t_is_sorted(dir, dir->next))
		{
			if (dir != *list)
				last->next = dir->next;
			else
				*list = dir->next;
			dir_swap(&dir);
			dir = *list;
		}
		else
		{
			last = dir;
			dir = dir->next ? dir->next : dir;
		}
	}
}

void	sort_dir(t_direct **list)
{
	t_direct	*dir;
	t_direct	*last;

	dir = *list;
	last = NULL;
	while (dir->next)
	{
		if ((r & dir->flags) ==
				is_sorted(dir->name, dir->next->name))
		{
			if (dir != *list)
				last->next = dir->next;
			else
				*list = dir->next;
			dir_swap(&dir);
			dir = *list;
		}
		else
		{
			last = dir;
			dir = dir->next ? dir->next : dir;
		}
	}
}
