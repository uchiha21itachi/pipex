#include "pipex.h"

void    exec_builtin(char **path, char **cmd, char **env)
{
    int     i;
    char    *temp;
    
    i = 0;
    (void)env;
    while (path[i] != NULL)
    {
        temp = ft_strjoin(path[i], "/");
        temp = ft_strjoin(temp, cmd[0]);
        execve(temp, cmd, env);
        free(temp);
        temp = NULL;
        i++;
    }
}

//[Write end of pipe in use] [Read close] [infile cmd1]
void    child_process_one(int pipe_fd[2], char **arg, char **path, char **env)
{
        int     infile_fd;
        char    **cmd_arg;

        close(pipe_fd[0]);
        if (access(arg[1], F_OK) < 0)
        {
            printf("access to infile fail\n");
            return;
        }
        infile_fd = open(arg[1], O_RDONLY, 0644);
        if (infile_fd < 0)
        {
            printf("Error in opening infile\n");
            return;
        }
        dup2(infile_fd, STDIN_FILENO);
        close(infile_fd);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);
        cmd_arg = ft_split(arg[2], ' ');
        exec_builtin(path, cmd_arg, env);
}

//[Read end of pipe in use] [Write close] [cmd2 outfile]
void    child_process_two(int pipe_fd[2], char **arg,  char **path, char **env)
{
        int     outfile_fd;
        char    **cmd_arg;

        close(pipe_fd[1]);
        outfile_fd = open(arg[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
        if (outfile_fd < 0)
        {
            printf("Error in opening outfile\n");
            return;
        }
        dup2(pipe_fd[0], STDIN_FILENO);
        close(pipe_fd[0]);
        dup2(outfile_fd, STDOUT_FILENO);
        close(outfile_fd);
        cmd_arg = ft_split(arg[3], ' ');
        exec_builtin(path, cmd_arg, env);
}

void    start_pipex(char **argv, char **env, char **path)
{
    int     pipe_fd[2];
    pid_t   pid1;
    pid_t   pid2;

    if (pipe(pipe_fd) < 0)
    {
        printf("error in opening pipe\n");
        return;
    }
    pid1 = fork();
    if (pid1 < 0)
    {
        printf("Error in forking\n");
        return;
    }
    if (pid1 == 0)
        child_process_one(pipe_fd, argv, path, env);
    pid2 = fork();
    if (pid2 < 0)
    {
        printf("Error in forking 2\n");
        return;
    }
    if (pid2 == 0)
        child_process_two(pipe_fd, argv, path, env);
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}   