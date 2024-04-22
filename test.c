#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s2[i] < s1[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strnstr(char *big, char *little, int len)
{
	int	i;

	if (*little == 0)
		return (big);
	i = ft_strlen(little);
	while (*big && i <= len)
	{
		if (*big == *little && ft_strncmp(big, little, i) == 0)
			return (big);
		big++;
		len--;
	}
	return ((void *)0);
}

int	is_space(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	is_next_string_space(char *token, char *user_input)
{
	char	*ptr;
	char	*ch;

	ch = "\0";
	ptr = ft_strnstr(user_input, token, ft_strlen(token));
	printf("pointer is at %s   token len is %d\n", ptr, ft_strlen(token));
	if (ptr)
		ch = ptr + ft_strlen(token);
	if (is_space(*ch))
		return(1);
	return (0);
}

int	main()
{
	char	*str = {"echo \"hello\"'PATH'"};
	char	*token = {"\"hello\""};

	printf("user input is %s\ntoken is %s\nis there space after token\n1-yes   0-no\n%d\n", str, token, is_next_string_space(token, str));
}