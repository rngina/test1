/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:30:52 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/19 15:15:59 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_inf(t_list *list)
{
	t_inf	*inf;

	inf = list->inf;
	while (inf)
	{
		printf("|%s %c|", inf->file, inf->flag);
		inf = inf->next;
	}
	printf("\n");
}

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
	// if (tokens)
	// {
	// 	while (*tokens)
	// 	{
	// 		printf("%s\n", *tokens);
	// 		tokens++;
	// 	}
	// }
	printf("im in input\n");
	list = parse(user_input, tokens, env_copy);
	printf("in input after parse() call\n");
	return(list);
}

int	main(int argc, char **argv, char **env)
{
	char	*user_input;
	char	**env_copy;
	t_list	*list;
	int		exit_status;

	env_copy = duplicate_env(env);
	exit_status = 0;
	while (true)
	{
		user_input = readline("minishell:~$ ");
		add_history(user_input);
		list = input(user_input, env_copy);
		printf("back to while loop\n");
		print_inf(list);
		printf("after expected print\n");
		//exec(&env_copy);
	}
	free(user_input);
	//free env_copy
	rl_clear_history();
}