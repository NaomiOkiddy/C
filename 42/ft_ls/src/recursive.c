/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:18:21 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/03 18:18:27 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			get_directory(t_directory **tmp, char *path, long int flags)
{
	DIR				*dir;
	struct dirent	*entry;
	char			pathname[STRING_MAX];
	size_t			len;

	len = ft_strlen(path);
	if (!(dir = opendir(path)))
		return ;
	add_directory(tmp, path, flags);
	while ((entry = readdir(dir)) != NULL)
	{
		get_pathname(pathname, path, entry->d_name);
		if (check_directory(pathname))
		{
			if (!ft_strcmp(entry->d_name, ".") ||
			!ft_strcmp(entry->d_name, ".."))
				continue;
			if (!(flags & ls_flag_a) && entry->d_name[0] == '.')
				continue;
			get_directory(tmp, pathname, flags);
		}
	}
	closedir(dir);
}

t_directory		*recursive_dir(int argc, char **argv, int count, long int flags)
{
	t_directory	*tmp;
	t_directory *first;

	tmp = NULL;
	if (count < argc)
	{
		while (count < argc)
		{
			get_directory(&tmp, argv[count], flags);
			count++;
		}
	}
	else
		get_directory(&tmp, ".", (flags | ls_flag_cur));
	sort_directory(&tmp, ft_strcmp);
	first = tmp;
	tmp = tmp->next;
	first->next = NULL;
	choose_sort(&tmp, flags);
	first->next = tmp;
	return (first);
}
