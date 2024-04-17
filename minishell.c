/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:30:52 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/17 14:45:39 by rtavabil         ###   ########.fr       */
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

t_list	*input(char *user_input, char **env_copy)
{
	char	**tokens;
	t_list	*list;

	list = NULL;
	tokens = get_tokens(user_input);
	if (tokens)
	{
		while (*tokens)
		{
			printf("%s\n", *tokens);
			tokens++;
		}
	}
	//list = parse(tokens, user_input, env);
	return(list);
}

int	main(int argc, char **argv, char **env)
{
	char	*user_input;
	char	**env_copy;
	int		exit_status;

	exit_status = 0;
	while (true)
	{
		env_copy = duplicate_env(env);
		user_input = readline("minishell:~$ ");
		add_history(user_input);
		input(user_input, env_copy);
		//exec();
	}
	free(user_input);
	//free env_copy
	rl_clear_history();
}