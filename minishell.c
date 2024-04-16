/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:30:52 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/16 18:32:13 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**duplicate_env(char **env)
{
	int		len;
	int		i;
	char	**dup_env;

	len = 0;
	i = 0;
	while (env[len] != NULL)
		len++;
	dup_env = malloc((len + 1) * sizeof(char *));
	while (i < len)
	{
		dup_env[i] = ft_strdup(env[i]);
		if (dup_env[i] == NULL)
			return (NULL);//malloc error
		i++;
	}
	dup_env[i] = NULL;
	return (dup_env);
}

int	main(int argc, char **argv, char **envp)
{
	char	*user_input;
	t_list	*envp_copy;
	char	**tokens;
	int		exit_status;

	exit_status = 0;
	while (true)
	{
		user_input = readline("minishell:~$ ");
		add_history(user_input);
		tokens = get_tokens(user_input);
		if (tokens)
		{
			while (*tokens)
			{
				printf("%s\n", *tokens);
				tokens++;
			}
		}
		//exec();
	}
	free(user_input);
	rl_clear_history();
}