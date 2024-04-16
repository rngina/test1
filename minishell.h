/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtavabil <rtavabil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:23:44 by rtavabil          #+#    #+#             */
/*   Updated: 2024/04/16 18:32:32 by rtavabil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h> //printf, readline
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h> //write, access, open, close, fork, getcwd
# include <stdlib.h> //malloc, free, NULL
# include <sys/types.h> //pid_t
# include <sys/wait.h> //wait
# include <stdbool.h> //booleans
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef enum e_builtins {
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
}	t_builtins;


typedef struct s_inf
{
	char			flag; // 'h' 'c'
	char			*file;
	struct s_inf	*next;
}	t_inf;

typedef struct s_outf
{
	char			flag; // 'a' 'c'
	char			*file;
	struct s_outf	*next;
}   t_outf;

// list structure:
typedef struct s_list
{
	int				list_id;
	char			*cmd;
	char			**argv;
	char			**env;
	t_inf			*inf;
	t_outf			*outf;
	struct s_list	*next;
}		t_list;

char	*ft_substr(char *s, int start, int len);
int		is_special(char c);
void	ft_bzero(void *dest, int byte_sizes);
void	*ft_calloc(int num, int byte_sizes);
char	*ft_strchr(char *s, int c);
int		ft_strchrin(char *s, int c);
int		ft_strlen(char *s);
char	*count_special(char *s);
int		ft_count_words(char *s);
int		is_space(int c);
int		count_quotes(char *s);
char	**split_quotes(char *s, int *i, char **res);
char	**split_red(char *s, int *i, char **res);
char	**split_pipe(char *s, int *i, char **res);
char	**split_process(char *s, char **res);
char	**ft_split(char *s);
char	**get_tokens(char *user_input);


//strings
char	*ft_strdup(char *src);





// //strings
// char	*ft_strrchr(char *s, int c);
// int		ft_strlen(char *s);
// int		ft_strncmp(char *s1, char *s2, int n);
// char	*ft_strstr(char *big, char *little);
// void	ft_putstr_fd(char *s, int fd);
// char	*ft_strjoin(char *s1, char *s2);
// int		ft_isspace(int c);
// char	*ft_strchr(char *s, int c);
// char	*ft_strcpy(char *dest, char *src);
// char	*ft_strdup(char *src);
// char	*ft_strndup(char *src, int len);



// //parsing
// void	prompt(void);

// char	**parse_user_input(char **user_input);
// char	*parse_argument(char **user_input);
// int		add_in_result(char *result, char *temp, int i, int index);
// int		add_in_argument(char **result, char *temp, int shift);
// char	*check_result(char *result, int index);


// //init
// // void	args_init(t_args *args);


// //utils
// void	*ft_malloc(int size);

// char	**ft_double_realloc(char **src, int size);
// void	*ft_realloc(char *src, int size);

#endif