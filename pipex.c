/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <yassharm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:51:26 by yassharm          #+#    #+#             */
/*   Updated: 2021/09/25 16:46:32 by yassharm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
    
    if (argc != 5)
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
    start_pipex(argv, env, path);
    free_double_char(path);
    return (0);   
}