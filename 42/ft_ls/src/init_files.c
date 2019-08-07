/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:00:38 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/05 16:00:39 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				get_files(DIR *directory, t_directory *dir)
{
	struct dirent	*dptr;
	int				file_count;
	char			temp_name[256];

	file_count = 0;
	ft_strcpy(temp_name, dir->dirname);
	while ((dptr = readdir(directory)))
	{
		add_files(dir, temp_name, dptr->d_name);
		file_count++;
	}
	dir->file_count = file_count + 1;
	sorting(dir);
	print_file(dir);
	return (0);
}

void			add_files(t_directory *dir, char *dirname, char *name)
{
	t_file *new;

	if (!(new = (t_file*)malloc(sizeof(t_file))))
		return ;
	new->name = ft_strdup(name);
	ft_strcat(dirname, "/");
	new->filepath = ft_strdup(dirname);
	new->next = dir->first_file;
	dir->first_file = new;
}

int				sorting(t_directory *dir)
{
	sort_file(dir, ft_strcmp);
	if (dir->flags & ls_flag_t)
		sort_file(dir, time_cmp);
	if (dir->flags & ls_flag_r)
		reverse_sort_file(dir);
	return (1);
}

void			sort_file(t_directory *dir, int (*cmp)())
{
	t_file	*current;
	int		sort;
	int		i;
	char	path1[STRING_MAX];
	char	path2[STRING_MAX];

	sort = 1;
	NULL_CHECK(!dir->first_file || !dir->first_file->next);
	while (sort)
	{
		sort = 0;
		current = dir->first_file;
		i = 1;
		while (++i < dir->file_count)
		{
			get_pathname(path1, dir->dirname, current->name);
			get_pathname(path2, dir->dirname, current->next->name);
			if ((*cmp)(path1, path2) > 0)
			{
				swap_file(&current, &current->next);
				sort = 1;
			}
			current = current->next;
		}
	}
}

void			swap_file(t_file **a, t_file **b)
{
	char	*temp_name;

	temp_name = (*a)->name;
	(*a)->name = (*b)->name;
	(*b)->name = temp_name;
}
