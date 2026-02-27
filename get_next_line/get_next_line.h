#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_gnl_strlen(char *s);

#endif
