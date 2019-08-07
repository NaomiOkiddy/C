/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:22:59 by nokiddy           #+#    #+#             */
/*   Updated: 2019/02/03 18:23:16 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			add_directory(t_directory **list, char *dirname, long int flags)
{
	t_directory *new;

	if (!(new = (t_directory*)malloc(sizeof(t_directory))))
		return ;
	new->dirname = ft_strdup(dirname);
	new->flags = flags;
	new->next = *list;
	*list = new;
	new->first_file = NULL;
}

void			choose_sort(t_directory **begin_list, long int flags)
{
	if (!(flags & ls_flag_cur))
		sort_directory(begin_list, ft_strcmp);
	if (flags & ls_flag_t)
		sort_directory(begin_list, time_cmp);
	if (flags & ls_flag_r)
		reverse_sort_directory(begin_list);
}

void			sort_directory(t_directory **begin_list, int (*cmp)())
{
	t_directory	*current;
	t_directory	*next;
	int			sort;

	sort = 1;
	current = *begin_list;
	if (!current || !current->next)
		return ;
	while (sort)
	{
		sort = 0;
		current = *begin_list;
		next = current->next;
		while (next)
		{
			if ((*cmp)(current->dirname, next->dirname) > 0)
			{
				swap_directory(&current, &next);
				sort = 1;
			}
			current = current->next;
			next = next->next;
		}
	}
}

void			swap_directory(t_directory **a, t_directory **b)
{
	char	*temp_dirname;

	temp_dirname = (*a)->dirname;
	(*a)->dirname = (*b)->dirname;
	(*b)->dirname = temp_dirname;
}

int				count_directory(t_directory **dir)
{
	int			i;
	t_directory	*temp;

	temp = *dir;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
