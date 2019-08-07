/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:38:11 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/04 13:38:12 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			reverse_sort_directory(t_directory **begin_list)
{
	t_directory	*prev;
	t_directory	*next;
	t_directory	*current;

	current = *begin_list;
	prev = 0;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

void			reverse_sort_file(t_directory *dir)
{
	t_file	*prev;
	t_file	*next;
	t_file	*current;
	int		i;

	current = dir->first_file;
	prev = 0;
	i = 0;
	while (++i < dir->file_count)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	dir->first_file = prev;
}

int				time_cmp(const char *path1, const char *path2)
{
	struct stat	temp1;
	struct stat	temp2;
	long		sec_diff;
	long		nsec_diff;

	lstat(path1, &temp1);
	lstat(path2, &temp2);
	sec_diff = temp2.st_mtimespec.tv_sec - temp1.st_mtimespec.tv_sec;
	if (!sec_diff)
	{
		nsec_diff = temp2.st_mtimespec.tv_nsec - temp1.st_mtimespec.tv_nsec;
		if (!nsec_diff)
			return (ft_strcmp(path1, path2));
		return (nsec_diff);
	}
	return (sec_diff);
}
