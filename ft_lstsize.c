/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_lstsize.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: crmanzan <crmanzan@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/30 18:02:29 by crmanzan		   #+#	  #+#			  */
/*	 Updated: 2024/04/30 18:02:31 by crmanzan		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
