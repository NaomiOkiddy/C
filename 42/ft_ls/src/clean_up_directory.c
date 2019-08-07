/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up_directory.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:26:41 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/04 13:32:36 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	act_on_strays(t_directory *strays)
{
	int			padding[4];
	int			i;
	t_file		*file;

	if (!strays->first_file)
		return ;
	sorting(strays);
	get_padding(strays, padding);
	file = strays->first_file;
	i = 0;
	while (++i < strays->file_count)
	{
		print_file_name(file, strays->flags, padding);
		file = file->next;
	}
	return ;
}

void	still_dealing_with_strays(t_directory **temp, t_directory **strays)
{
	t_directory	*prev;
	t_directory *tmp;
	t_directory *stry;

	tmp = *temp;
	stry = *strays;
	while (tmp)
	{
		while (tmp != 0 && check_directory(tmp->dirname))
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == 0)
			return (act_on_strays(stry));
		add_files(stry, stry->dirname, tmp->dirname);
		stry->file_count++;
		prev->next = tmp->next;
		free(tmp);
		tmp = prev->next;
	}
}

void	deal_with_strays(t_directory **list)
{
	t_directory	*temp;
	t_directory	*strays;

	temp = *list;
	add_directory(&strays, ".", temp->flags);
	strays->file_count = 1;
	while (temp != 0 && !check_directory(temp->dirname))
	{
		add_files(strays, strays->dirname, temp->dirname);
		strays->file_count++;
		*list = temp->next;
		free(temp);
		temp = *list;
	}
	still_dealing_with_strays(&temp, &strays);
	act_on_strays(strays);
}

void	remove_directory(t_directory **list)
{
	t_directory	*temp;
	t_directory	*prev;

	temp = *list;
	while (temp != 0 && !check_exists(temp->dirname))
	{
		print_dir_error(temp->dirname);
		*list = temp->next;
		free(temp);
		temp = *list;
	}
	while (temp)
	{
		while (temp != 0 && check_exists(temp->dirname))
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == 0)
			return ;
		print_dir_error(temp->dirname);
		prev->next = temp->next;
		free(temp);
		temp = prev->next;
	}
}

void	open_directory(t_directory **list, int num_directory)
{
	DIR			*directory;
	t_directory	*temp;

	printf("%d\n", num_directory);
	remove_directory(list);
	if (!*list)
		exit(1);
	deal_with_strays(list);
	temp = *list;
	while (temp)
	{
		directory = opendir(temp->dirname);
		if (num_directory <= 1 && ())
			get_files(directory, temp);
		else
		{
			print_dirname(temp->dirname, temp->flags);
			get_files(directory, temp);
		}
		if (temp->next)
			ft_putchar('\n');
		closedir(directory);
		temp = temp->next;
	}
	delete_dir(list);
}
