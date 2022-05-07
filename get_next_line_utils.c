#include "get_next_line.h"

char	*ft_strchr(char *s, char ch)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

int	len(char *str, char symb)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != symb)
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len, int flag_free)
{
	int		i;
	char	*str;

	i = 0;
	if (len == 0 && flag_free == 1)
	{
		free(s);
		return (0);
	}
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (0);
	while (s[start] && len > i)
		str[i++] = s[start++];
	if (flag_free == 1)
		free(s);
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	k = 0;
	str = (char *)malloc(sizeof(char) * (len(s2, '\0') + len(s1, '\0') + 1));
	if (!str)
	{
		free (str);
		return (0);
	}
	if (len(s2, '\0') + len(s1, '\0') > 0)
	{
		while (s1 && s1[k] != '\0')
			str[i++] = s1[k++];
		k = 0;
		while (s2 && s2[k] != '\0')
			str[i++] = s2[k++];
	}
	if (s1)
		free(s1);
	str[i] = '\0';
	return (str);
}
