/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:57:12 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/18 18:25:53 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s2[i] < s1[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_special_str(char *str)
{
	if (ft_strcmp(*str, ">"))
		return (1);
	if (ft_strcmp(*str, "<"))
		return (1);
	if (ft_strcmp(*str, ">>"))
		return (1);
	if (ft_strcmp(*str, "<<"))
		return (1);
	if (ft_strcmp(*str, "|"))
		return (1);
	if (ft_strcmp(*str, "$"))
		return (1);
	return (0);
}

void	add_next_inf(t_list **list, char *file, char *flag)
{
	//todo
	//init inf
	//set value and flag
	//add last list->inf
}

void	add_next_outf(t_list **list, char *file, char *flag)
{
	//todo
	//init outf
	//set value and flag
	//add last list->outf
}

void	parse_red(char **tokens, t_list **list)
{
	if (!ft_strcmp(*tokens, "<") || !ft_strcmp(*tokens, "<<"))
	{
		if (!is_special_str(*(tokens + 1)) && *tokens)
			add_next_inf(list, *(tokens + 1), *tokens);
		else
			redirect_error(); //TODO syntax error near unexpected token [*(tokens + 1)] 
	}
	if (!ft_strcmp(*tokens, ">") || !ft_strcmp(*tokens, ">>"))
	{
		if (!is_special_str(*(tokens + 1)) && *tokens)
			add_next_outf(list, *(tokens + 1), *tokens);
		else
			redirect_error(); //TODO syntax error near unexpected token [*(tokens + 1)]
	}
}

t_list	*parse_pipe(t_list **list, char **tokens, char **env)
{
	//TODO
	//check if list has a command 
	//if not 
	//pipe_error() syntax error near unexpected token `|'
	//check if tokens has something after (not pipe)
	//if not
	//pipe_error() syntax error near unexpected token `|'
	//create new t_list instance
	//return list instance
}

void	parse_exp(t_list **list, char **tokens, \
				char *user_input, char **env)
{
	//check if space after
	//if not concatenate with next 
	//if next is ''
	//expand /0 /a /b /t /n /v /f /r
}


void	parse_no_q()
{
	
}

void	parse_string(t_list **list, char *user_input, char ***tokens)
{
	//parse_double()
	//parse_single()
	//parse_no_q()

	//check if it has space in user input
	//if not and if next token is string -> concatenate with next

	//check $ sign
}

void	parse(char *user_input, char **tokens, char **env_copy)
{
	t_list	*list;
	t_list	*current;

	list = init_list(env_copy);
	current = list;
	while (*tokens)
	{
		if (!ft_strcmp(*tokens, ">") || !ft_strcmp(*tokens, "<") || \
			!ft_strcmp(*tokens, ">>") || !ft_strcmp(*tokens, "<<"))
			parse_red(tokens, &current);
		if (!ft_strcmp(*tokens, "|"))
			current = parse_pipe(&current, tokens + 1, env_copy);
		if (!ft_strcmp(*tokens, "$"))
			parse_exp(&current, tokens, user_input, env_copy);
		else 
			parse_string(&current, user_input, &tokens);
		tokens++;
	}
}

