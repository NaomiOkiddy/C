/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:13:48 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/05 15:13:50 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			get_pathname(char *pathname, const char *filepath,
const char *name)
{
	ft_strcpy(pathname, filepath);
	ft_strcat(pathname, "/");
	ft_strcat(pathname, name);
	ft_strcat(pathname, "\0");
}

int				get_bloc_size(t_directory *dir)
{
	t_file		*temp_file;
	struct stat	temp_buf;
	int			i;
	int			bloc_size;
	char		pathname[STRING_MAX];

	i = 0;
	bloc_size = 0;
	temp_file = dir->first_file;
	while (++i < dir->file_count)
	{
		if (temp_file->name[0] == '.' && !(dir->flags & ls_flag_a))
			;
		else
		{
			get_pathname(pathname, temp_file->filepath, temp_file->name);
			lstat(pathname, &temp_buf);
			bloc_size += temp_buf.st_blocks;
		}
		temp_file = temp_file->next;
	}
	return (bloc_size);
}

void			get_padding(t_directory *dir, int *padding)
{
	t_file			*temp_file;
	struct stat		temp_buf;
	int				i;
	char			pathname[STRING_MAX];

	i = 4;
	temp_file = dir->first_file;
	while (--i > 0)
		padding[i] = 0;
	while (++i < dir->file_count)
	{
		if (temp_file->name[0] != '.' || (dir->flags & ls_flag_a))
		{
			get_pathname(pathname, temp_file->filepath, temp_file->name);
			lstat(pathname, &temp_buf);
			padding[0] = ft_max(padding[0], ft_numlen(temp_buf.st_nlink));
			padding[1] = ft_max(padding[1], (int)ft_strlen(
				getpwuid(temp_buf.st_uid)->pw_name));
			padding[2] = ft_max(padding[2], (int)ft_strlen(
				getgrgid(temp_buf.st_gid)->gr_name));
			padding[3] = ft_max(padding[3], ft_numlen(temp_buf.st_size));
		}
		temp_file = temp_file->next;
	}
}
