#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		len(char *str, char symb);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len, int flag_free);
int		get_next_line(int fd, char **line);
char	*ft_strchr(char *s, char ch);
#endif