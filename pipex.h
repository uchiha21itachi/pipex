#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
void    free_doub_char(char **str);

//start_pipex.c
void    start_pipex(char **argv, char **env, char **path);

//pipex.c
void    print_path(char **path);


#endif