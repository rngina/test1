/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_inf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:34:46 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/18 15:41:59 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_inf	*init_inf(void)
{
	t_inf	*inf;

	inf = malloc(sizeof(t_inf));
	if (!inf)
		return (NULL);
	inf->flag = '\0';
	inf->file = NULL;
	inf->next = NULL;
	return (inf);
}

t_inf	*ft_lstinf(t_inf *inf)
{
	if (!inf)
		return (NULL);
	while (inf->next)
		inf = inf->next;
	return (inf);
}

void	add_last_inf(t_inf **head, t_inf *inf)
{
	t_inf	*node;

	if (!inf)
		return ;
	if (!*head)
	{
		*head = inf;
		return ;
	}
	node = ft_lstinf(*head);
	node->next = inf;
}