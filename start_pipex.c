#include "pipex.h"

void    exec_builtin(char **path, char **builtin, char **env)
{
    int     i;
    char    *temp;
    
    i = 0;
    while (path[i] != NULL)
    {
        temp = ft_strjoin(path[i], "/");
        temp = ft_strjoin(temp, builtin[0]);
        execve(temp, builtin, env);
        temp = NULL;
        i++;
    }
}

void    call_child(char **argv, char **env, char **path, int pipe_fd)
{
    char    **builtin;  
    char    *temp;
    int     fd;

    printf("\ninside child process\n");
    temp = ft_strdup(argv[2]);
    builtin = ft_split(temp, ' ');
    print_path(builtin);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        printf("Error in opening the file\n");
        close(pipe_fd);
        free(temp);
        free_doub_char(builtin);
        return;
    }

    printf("file opened to read fd [%d]\n pipe_fd in child[%d]", fd, pipe_fd);
    dup2(fd, STDIN_FILENO);
    close(fd);
    dup2(pipe_fd, STDOUT_FILENO);
    close(pipe_fd);
    exec_builtin(path, builtin, env);

    (void)argv;
    (void)path;
    (void)env;
    free(temp);
    free_doub_char(builtin);
}

void    call_parent(char **argv, char **env, char **path, int pipe_fd)
{
    char    **builtin;
    char    *temp;
    // int     fd;

    printf("\ninside Parent process\n");
    temp = ft_strdup(argv[3]);
    builtin = ft_split(temp, ' ');
    print_path(builtin);
    // (void)argv;
    // (void)path;
    // (void)env;
    // (void)pipe_fd;
    dup2(pipe_fd, STDIN_FILENO); 
    close(pipe_fd);
    exec_builtin(path, builtin, env);
    free(temp);
    free_doub_char(builtin);
}

void    start_pipex(char **argv, char **env, char **path)
{
    int     pipe_fd[2];
    pid_t   pid;
    // pid_t   j;
    // int     i;

    if (pipe(pipe_fd) < 0)
    {
        printf("error in opening pipe\n");
        return;
    }
    printf("pipe fd[0] - [%d] \npipe fd [1] -[%d]\n", pipe_fd[0], pipe_fd[1]);
    pid = fork();
    if (pid == 0)
    {
        close(pipe_fd[0]);
        call_child(argv, env, path, pipe_fd[1]);
    }
    else
    {
        close(pipe_fd[1]);
        call_parent(argv, env, path, pipe_fd[0]);
    }
    // j = waitpid(pid, &i, WNOHANG);
    (void)argv;
    (void)path;
    (void)env;
    // (void)j;
}   