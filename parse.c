/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:57:12 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/23 16:51:25 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

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
	if (!ft_strcmp(str, ">"))
		return (1);
	if (!ft_strcmp(str, "<"))
		return (1);
	if (!ft_strcmp(str, ">>"))
		return (1);
	if (!ft_strcmp(str, "<<"))
		return (1);
	if (!ft_strcmp(str, "|"))
		return (1);
	if (!ft_strcmp(str, "$"))
		return (1);
	return (0);
}

void	add_next_inf(t_list **list, char *file, char *flag)
{
	char	inf_flag;
	t_inf	*infile;
	//todo
	//init inf
	//set value and flag
	//add last list->inf
	printf("from func file = %s,flag = %s\n", file, flag);
	inf_flag = 'c';
	if (!ft_strcmp(flag, "<<"))
		inf_flag = 'h';
	infile = init_inf(file, inf_flag);
	add_last_inf(&((*list)->inf), infile);
}

void	add_next_outf(t_list **list, char *file, char *flag)
{
	char	out_flag;
	t_outf	*outfile;
	//todo
	//init outf
	//set value and flag
	//add last list->outf
	printf("from func file = %s,flag = %s\n", file, flag);
	out_flag = 'c';
	if (!ft_strcmp(flag, ">>"))
		out_flag = 'a';
	outfile = init_outf(file, out_flag);
	add_last_outf(&((*list)->outf), outfile);
}

void	parse_red(char **tokens, t_list **list)
{
	printf("entered parse_red");
	printf(" check list %s\n", *(*list)->env);
	if (!ft_strcmp(*tokens, "<") || !ft_strcmp(*tokens, "<<"))
	{
		if (!is_special_str(*(tokens + 1)) && *tokens)
			add_next_inf(list, *(tokens + 1), *tokens);
		// else
		// 	redirect_error(); //TODO syntax error near unexpected token [*(tokens + 1)] 
	}
	if (!ft_strcmp(*tokens, ">") || !ft_strcmp(*tokens, ">>"))
	{
		if (!is_special_str(*(tokens + 1)) && *tokens)
			add_next_outf(list, *(tokens + 1), *tokens);
		// else
		// 	redirect_error(); //TODO syntax error near unexpected token [*(tokens + 1)]
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
	return (NULL);
}

void	parse_exp(t_list **list, char **tokens, \
				char *user_input, char **env)
{
	//check if space after
	//if not concatenate with next 
	//if next is ''
	//expand /0 /a /b /t /n /v /f /r
	return ;
}


char	*parse_no_q()
{
	//check if next is ' or " or $
	//if yes check for space 
	//if no space concatenate
	//return as it is?
	return (NULL);
}

int	is_alphanum(char c)
{
	if (((c >= 48) && (c <= 57)) || ((c >=97 && c <= 122)) \
		|| (c == 45) || ((c >= 65) && (c <= 90)))
		return (1);
	return (0);
}

char	*parse_double(char *token, char **env)
{
	int		i;
	int		start;
	char	*parsed;
	char	*env_char;
	int		len;
	char	*env_var;

	start = -1;
	env_char = NULL;
	env_var = NULL;
	if (ft_strchrin(token, '$') != -1)
	{
		printf("entered parse_double() if\n");
		start = ft_strchrin(token, '$') + 1;
		i = start + 1;
		while (token[i])
		{
			if (!is_alphanum(token[i]))
				break;
			i++;
		}
		if (i - start > 1)
		{
			printf("entered parse_double() if() if()\n");
			env_char = ft_substr(token, start, i - start);
			printf("env_char is %s\n", env_char);
		}

	}
	// if (env_char)
	// {
	// 	len = ft_strlen(token) - 3 + ft_strlen(env_char);
	// 	parsed = (char *)malloc((len + 1) * sizeof(char));
	// 	if (!parsed)
	// 		return (NULL);
	// 	env_var = 
	// }
	len = ft_strlen(token - 2);
	if (env_char)
		len += ft_strlen(env_char);
	parsed = (char *)malloc((len + 1) * sizeof(char));
	if (!parsed)
		return (NULL);
	ft_strlcpy(parsed, token + 1, ft_strlen(token) - 1);
	if (env_char)
	{
		ft_strlcpy(token + ft_strlen(token) - 2, env_char, ft_strlen(env_char) + 1);
		free(env_char);
	}
	
	//remove quotes
	//-assign new memory
	//-substr from 1 to len - 1
	//free old one
	//check for $ sign
	//if yes expand 
	return (parsed);
}

char	*parse_single()
{
	//remove quotes
	//-assign new memory
	//-substr from 1 to len - 1
	//free old one
	//check for $ sign
	//if yes expand 
	return (NULL);
}

int	is_next_string_space(char *token, char *user_input)
{
	char	*ptr;
	char	ch;

	ptr = ft_strnstr(user_input, token, ft_strlen(user_input));
	ch = *(ptr + ft_strlen(token));
	if (is_space(ch))
		return(1);
	return (0);
}

char	*return_string(t_list **list, char *user_input, char ***tokens)
{
	char	*token;
	char	**temp;

	temp = *tokens;
	token = NULL;
	if (**temp == '\"')
	{
		printf("token is %s\n", *temp);
		token = parse_double(*temp, (*list)->env);
	}
	else if (*user_input == '\'')
		token = parse_single();
	else
		token = parse_no_q();
	// if ((*tokens + 1) && !is_special_str(*(*tokens + 1)))
	// {
	// 	temp = *tokens + 1;
	// 	next = return_string(list, user_input, &temp);
	// 	ptr = ft_strnstr(user_input, next, ft_strlen(next));
	// 	if (is_space(*(ptr + ft_strlen(*(*tokens + 1)))))
	// 	{
	// 		next = return_string(list, user_input, tokens);
	// 		(*tokens)++;
			
	// 		//increment tokens
	// 		//concatenate with token
	// 	}
	// }
	// //check if it has space in user input
	// //if not and if next token is string -> concatenate with next

	// //check $ sign
	return (token);
}

void	parse_string(t_list **list, char *user_input, char ***tokens)
{
	//TODO
	char	*str;

	str = return_string(list, user_input, tokens);
	// if (str)
	// 	argv_add((*list)->argv, str); //TODO
	printf("string is %s\n", str);
}

t_list	*parse(char *user_input, char **tokens, char **env_copy)
{
	t_list	*list;
	t_list	*current;

	printf("entered parse()\n");
	list = init_list(env_copy);
	current = list;
	while (*tokens)
	{
		printf("entered while\n");
		if (!ft_strcmp(*tokens, ">") || !ft_strcmp(*tokens, "<") || \
			!ft_strcmp(*tokens, ">>") || !ft_strcmp(*tokens, "<<"))
			{
				printf("passed if\n");
				parse_red(tokens, &current);
			}
		if (!ft_strcmp(*tokens, "|"))
			current = parse_pipe(&current, tokens + 1, env_copy);
		//make all function return value for outputting errors
		if (!ft_strcmp(*tokens, "$"))
			parse_exp(&current, tokens, user_input, env_copy);
		else 
			parse_string(&current, user_input, &tokens);
		tokens++;
	}
	printf("finished parse()\n");
	return (list);
}

