/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:48:39 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/05 15:48:41 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_type(mode_t permissions)
{
	int perm;

	perm = permissions & S_IFMT;
	if (perm == S_IFLNK)
		ft_putstr("l");
	else if (perm == S_IFDIR)
		ft_putstr("d");
	else if (perm == S_IFBLK)
		ft_putstr("b");
	else if (perm == S_IFCHR)
		ft_putstr("c");
	else if (perm == S_IFIFO)
		ft_putstr("f");
	else if (perm == S_IFSOCK)
		ft_putstr("s");
	else
		ft_putstr("-");
}

void	print_permissions(mode_t permissions)
{
	ft_putstr((permissions & S_IRUSR) ? "r" : "-");
	ft_putstr((permissions & S_IWUSR) ? "w" : "-");
	ft_putstr((permissions & S_IXUSR) ? "x" : "-");
	ft_putstr((permissions & S_IRGRP) ? "r" : "-");
	ft_putstr((permissions & S_IWGRP) ? "w" : "-");
	ft_putstr((permissions & S_IXGRP) ? "x" : "-");
	ft_putstr((permissions & S_IROTH) ? "r" : "-");
	ft_putstr((permissions & S_IWOTH) ? "w" : "-");
	ft_putstr((permissions & S_IXOTH) ? "x" : "-");
}

void	print_link(t_file *a)
{
	char	pathname[STRING_MAX];
	char	linkname[4097];
	int		size;

	get_pathname(pathname, a->filepath, a->name);
	ft_bzero(linkname, 4097);
	size = readlink(pathname, linkname, 4096);
	if (size > 0)
	{
		ft_putstr(" -> ");
		ft_putstr(linkname);
	}
}

void	print_xattr(char *pathname)
{
	int xat;

	xat = listxattr(pathname, 0, 0, XATTR_NOFOLLOW);
	if (xat > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
}

void	print_date(struct stat *stat)
{
	time_t		current;
	time_t		mtime;
	time_t		diff;
	char		*date_time;

	current = time(NULL);
	mtime = stat->st_mtime;
	date_time = ctime(&mtime);
	diff = current - mtime;
	ft_putchar(' ');
	string_precision(&(date_time[4]), 6);
	ft_putchar(' ');
	if (diff > 15770000 || diff < -15770000)
	{
		ft_putchar(' ');
		string_precision(&(date_time[20]), 4);
	}
	else
		string_precision(&(date_time[11]), 5);
	ft_putchar(' ');
}
