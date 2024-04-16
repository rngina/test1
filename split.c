/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:39:12 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/16 15:35:01 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_quotes(char *s, int *i, char **res)
{
	int	start;

	start = -1;
	if (s[*i] == '\"')
	{
		start = *i;
		*i = ft_strchrin(&s[*i + 1], '\"');
		if (i > 0)
			*res++ = ft_substr(s, start, *i + 2);
		*i = start + *i + 2;
	}
	else if (s[*i] == '\'')
	{
		start = *i;
		*i = ft_strchrin(&s[*i + 1], '\'');
		if (*i > 0)
			*res++ = ft_substr(s, start, *i + 2);
		*i = start + *i + 2;
	}
	return (res);
}

char	**split_red(char *s, int *i, char **res)
{
	if (s[*i] == '>')
	{
		if (s[*i + 1] == '>')
		{
			*res++ = ft_substr(s, *i, 2);
			*i = *i + 1;
		}
		else
			*res++ = ft_substr(s, *i, 1);
	}
	else if (s[*i] == '<')
	{
		if (s[*i + 1] == '<')
		{
			*res++ = ft_substr(s, *i, 2);
			*i = *i + 1;
		}
		else
			*res++ = ft_substr(s, *i, 1);
	}
	*i = *i + 1;
	return (res);
}

char	**split_pipe(char *s, int *i, char **res)
{
	*res++ = ft_substr(s, *i, 1);
	*i = *i + 1;
	return (res);
}

char	**split_process(char *s, char c, char **res)
{
	int		i;
	int		start;

	i = 0;
	start = -1;
	while (i <= ft_strlen(s) && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\'' || s[i] == '\"')
			res = split_quotes(s, &i, res);
		else if (s[i] == '>' || s[i] == '<')
			res = split_red(s, &i, res);
		else if (s[i] == '|')
			res = split_pipe(s, &i, res);
		else if (s[i] != c)
		{
			start = (int)i;
			while (s[i] != c && s[i] != '\0' && !is_special(s[i]))
				i++;
			if (i - start > 0)
				*res++ = ft_substr(s, start, i - start);
		}
	}
	return (res);
}

char	**ft_split(char *s, char c)
{
	char	**res;

	res = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !res)
		return ((void *)0);
	res = split_process(s, c, res);
	*res = (void *)0;
	return (res - ft_count_words(s, c));
}

int	main(int argc, char **argv, char **envp)
{
	char **table;
	char *str = {"|<infile<<<xxx   | ||  echo \" hello | world  \"'PATH\'here<<"};

	printf("%s\n", str);
	printf("_________________________________\n");
	table = ft_split(str, ' ');
	while (*table)
	{
		printf("%s\n", *table);
		table++;
	}
}

		// if (s[i] == '\"')
		// {
		// 	start = i;
		// 	i = ft_strchrin(&s[i + 1], '\"');
		// 	if (i > 0)
		// 		*res++ = ft_substr(s, start, i + 2);
		// 	i = start + i + 2;
		// }
		// else if (s[i] == '\'')
		// {
		// 	start = i;
		// 	i = ft_strchrin(&s[i + 1], '\'');
		// 	if (i > 0)
		// 		*res++ = ft_substr(s, start, i + 2);
		// 	i = start + i + 2;
		// }
				// else if (s[i] == '>')
		// {
		// 	if (s[i + 1] == '>')
		// 	{
		// 		*res++ = ft_substr(s, i, 2);
		// 		i = i + 2;
		// 	}
		// 	else 
		// 	{
		// 		*res++ = ft_substr(s, i, 1);
		// 		i = i + 1;
		// 	}
		// }
		// else if (s[i] == '<')
		// {
		// 	if (s[i + 1] == '<')
		// 	{
		// 		*res++ = ft_substr(s, i, 2);
		// 		i = i + 2;
		// 	}
		// 	else 
		// 	{
		// 		*res++ = ft_substr(s, i, 1);
		// 		i = i + 1;
		// 	}
		// }