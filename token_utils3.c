/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:54:27 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/16 16:54:39 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quotes(char *s)
{
	int	i;
	int	index;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == '\'')
		{
			index = ft_strchrin(&s[i + 1], '\'');
			if (index < 0)
				return (1);
			i = i + index + 1;
		}
		else if (s[i] == '\"')
		{
			index = ft_strchrin(&s[i + 1], '\"');
			if (index < 0)
				return (1);
			i = i + index + 1;
		}
		else 
			i++;
		printf("%d\n", i);
	}
	return (0);
}
