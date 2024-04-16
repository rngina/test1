/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:59:14 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/16 18:48:09 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *src)
{
	char	*result;
	int	i;

	i = 0;
	result = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!result)
		return (NULL);
	while (*src)
		result[i++] = *(src++);
	result[i] = '\0';
	return (result);
}
