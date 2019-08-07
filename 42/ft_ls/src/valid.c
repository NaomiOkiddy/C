/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:32:29 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/04 13:36:28 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				check_exists(char *pathname)
{
	struct stat		temp;
	int				perm;
	int				permissions;

	if (lstat(pathname, &temp) == -1)
		return (0);
	permissions = temp.st_mode;
	perm = permissions & S_IFMT;
	if (perm == S_IFLNK)
		return (1);
	else if (perm == S_IFDIR)
		return (1);
	else if (perm == S_IFBLK)
		return (1);
	else if (perm == S_IFCHR)
		return (1);
	else if (perm == S_IFIFO)
		return (1);
	else if (perm == S_IFSOCK)
		return (1);
	else if (perm == S_IFREG)
		return (1);
	return (0);
}

int				check_directory(char *pathname)
{
	DIR *directory;

	if (!(directory = opendir(pathname)))
		return (0);
	closedir(directory);
	return (1);
}
