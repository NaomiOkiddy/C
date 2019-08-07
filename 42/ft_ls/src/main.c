/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:37:23 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/04 13:37:25 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				delete_files(t_file **fil)
{
	t_file *delete;

	while (*fil)
	{
		delete = (*fil)->next;
		free((*fil)->filepath);
		free((*fil)->name);
		ft_memdel((void *)fil);
		*fil = delete;
	}
}

void				delete_dir(t_directory **dir)
{
	t_directory *delete;

	while (*dir)
	{
		delete = (*dir)->next;
		delete_files(&(*dir)->first_file);
		free((*dir)->dirname);
		ft_memdel((void *)dir);
		*dir = delete;
	}
}

void				parse_command(int argc, char **argv)
{
	int			i;
	long int	temp_flags;
	t_directory	*directory_list;

	temp_flags = 0;
	directory_list = NULL;
	i = count_flags(&temp_flags, argv, argc);
	if (temp_flags & ls_flag_R)
		directory_list = recursive_dir(argc, argv, i, temp_flags);
	else if (i < argc)
	{
		while (i < argc)
		{
			add_directory(&directory_list, argv[i], temp_flags);
			i++;
		}
		choose_sort(&directory_list, temp_flags);
	}
	else
		add_directory(&directory_list, ".", temp_flags);
	open_directory(&directory_list, count_directory(&directory_list));
}

int					main(int argc, char **argv)
{
	if (argc >= 1)
		parse_command(argc, argv);
	else
		return (1);
	return (0);
}
