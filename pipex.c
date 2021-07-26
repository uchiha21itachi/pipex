#include "pipex.h"

void    print_path(char **path)
{
    int i;

    i = 0;
    printf("inside printing thing\n");
    while (path[i] != NULL)
    {
        printf("i [%d] [%s]\n", i, path[i]);
        i++;
    }
    printf("i [%d] [%s]\n", i, path[i]);
}

char **find_path(char **env)
{
    int     i;
    char    *temp;
    char    **path;

    i = 0;
    temp = NULL;
    while (env[i] != 0)
    {
        if (ft_strncmp(env[i], "PATH", 4) == 0)
            temp = ft_strdup(env[i]);
        i++;
    }
    if (temp == NULL)
        printf("something wrong happened\n");
    // else
        // printf("\nPath found is \n[%s]\n\n\n", temp);
    i = 0;
    while (temp[i] != '=')
        i++;
    i++;
    path = ft_split(temp + i, ':');
    free(temp);
    return (path);
} 

int main(int argc, char **argv, char **env)
{
    char **path;
    
    if (argc != 5 && argc != 4)
    {
        printf("Wrong arg please enter correct shit\n");
        return (1);
    }
    path = find_path(env);
    if (path == NULL)
    {
        printf("Path not found\nPlease try again\n");
        return (2);
    }
    // print_path(path);
    start_pipex(argv, env, path);
    free_doub_char(path);
    return (0);   
}