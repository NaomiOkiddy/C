/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nokiddy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 17:20:07 by nokiddy           #+#    #+#             */
/*   Updated: 2018/09/14 17:20:09 by nokiddy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
		new->content = NULL;
	else
	{
		new->content = ft_memalloc(content_size);
		if (!new->content)
		{
			ft_memdel((void **)&new);
			return (NULL);
		}
		ft_memcpy(new->content, content, content_size);
	}
	new->content_size = (content == NULL) ? 0 : content_size;
	new->next = NULL;
	return (new);
}