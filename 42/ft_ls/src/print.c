/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:46:34 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/05 15:46:35 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file_details(t_file *a, int *padding)
{
	char pathname[STRING_MAX];

	get_pathname(pathname, a->filepath, a->name);
	lstat(pathname, &a->buf);
	print_type(a->buf.st_mode);
	print_permissions(a->buf.st_mode);
	print_xattr(pathname);
	print_nlink(a->buf.st_nlink, padding[0]);
	(getpwuid(a->buf.st_uid)) ?
	left_justify_string(getpwuid(a->buf.st_uid)->pw_name, padding[1]) :
	left_justify(a->buf.st_uid, padding[1]);
	ft_putspace(2);
	left_justify_string(getgrgid(a->buf.st_gid)->gr_name, padding[2]);
	ft_putspace(2);
	print_size(a->buf.st_size, padding[3]);
	print_date(&a->buf);
}

void	print_file_name(t_file *a, long int print_flags, int *padding)
{
	if (print_flags & ls_flag_l)
		print_file_details(a, padding);
	ft_putstr(a->name);
	if ((print_flags & ls_flag_l) && (a->buf.st_mode & S_IFMT) == S_IFLNK)
		print_link(a);
	ft_putstr("\n");
}

void	print_dirname(char *dirname, long int flags)
{
	if (flags & ls_flag_R)
	{
		if (!(flags & ls_flag_cur))
		{
			ft_putstr(dirname);
			ft_putstr(":\n");
		}
		else
		{
			if (ft_strcmp(dirname, "."))
			{
				ft_putstr(dirname);
				ft_putstr(":\n");
			}
		}
	}
	else
	{
		ft_putstr(dirname);
		ft_putstr(":\n");
	}
}

void	print_bloc_size(int size)
{
	ft_putstr("total ");
	ft_putnbr(size);
	ft_putchar('\n');
}

void	print_file(t_directory *dir)
{
	t_file	*temp;
	int		i;
	int		padding[4];

	i = 0;
	temp = dir->first_file;
	if (dir->flags & ls_flag_l)
	{
		get_padding(dir, padding);
		print_bloc_size(get_bloc_size(dir));
	}
	while (++i < dir->file_count)
	{
		if (temp->name[0] == '.' && !(dir->flags & ls_flag_a))
			;
		else
			print_file_name(temp, dir->flags, padding);
		temp = temp->next;
	}
}
