#include "pipex.h"

void    call_child(char **argv, char **env, char **path, int pipe_fd)
{
    char **builtin;
    char *temp;

    temp = ft_strdup(argv[2]);
    builtin = ft_split(temp, ' ');
    print_path(builtin);
    free(temp);
    free_doub_char(builtin);
    (void)path;
    (void)argv;
    (void)env;
    close(pipe_fd);
}

void    call_parent(char **argv, char **env, char **path, int pipe_fd)
{
    char **builtin;
    char *temp;

    temp = ft_strdup(argv[3]);
    builtin = ft_split(temp, ' ');
    print_path(builtin);
    free(temp);
    free_doub_char(builtin);
    (void)path;
    (void)argv;
    (void)env;
    close(pipe_fd);
}

void    start_pipex(char **argv, char **env, char **path)
{
    int     pipe_fd[2];
    int     pid;

    if (pipe(pipe_fd) < 0)
    {
        printf("error in opening pipe\n");
        return;
    }
    pid = fork();
    if (pid == 0)
    {
        close(pipe_fd[1]);
        call_child(argv, env, path, pipe_fd[0]);
    }
    else
    {
        close(pipe_fd[0]);
        call_parent(argv, env, path, pipe_fd[1]);
    }
}
