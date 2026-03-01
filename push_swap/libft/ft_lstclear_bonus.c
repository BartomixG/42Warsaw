/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:58:52 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/19 14:29:35 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*current;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		current = *lst;
		next_node = (*lst)->next;
		ft_lstdelone(current, del);
		*lst = next_node;
	}
	*lst = NULL;
}
