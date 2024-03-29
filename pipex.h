#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

//utils.c
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *s1);
size_t	ft_strlen(char *s);
char	*ft_strndup(char *s1, size_t length);
char	*ft_strjoin(char *s1, char const *s2);

//utils_pipex.c
char    **ft_split(char *str, char c);
void    free_double_char(char **str);

//start_pipex.c
int    start_pipex(char **argv, char **env, char **path);
int     clean_exit(char *err_msg);

//pipex.c
void    print_path(char **path);


#endif