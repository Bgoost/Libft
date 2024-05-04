/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_lstdelone.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: crmanzan <crmanzan@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/04/30 18:34:35 by crmanzan		   #+#	  #+#			  */
/*	 Updated: 2024/04/30 18:34:35 by crmanzan		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
