/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmanzan <crmanzan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:25:32 by crmanzan          #+#    #+#             */
/*   Updated: 2024/05/04 20:46:41 by crmanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*new;
	void	*aux;

	if (!lst || !f || !del)
		return (NULL);
	lst2 = NULL;
	while (lst != NULL)
	{
		aux = f(lst->content);
		new = ft_lstnew(aux);
		if (!new)
		{
			ft_lstclear(&lst2, del);
			del(aux);
			return (NULL);
		}
		ft_lstadd_back(&lst2, new);
		lst = lst->next;
	}
	return (lst2);
}
