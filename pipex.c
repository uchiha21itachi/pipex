/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassharm <yassharm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:51:26 by yassharm          #+#    #+#             */
/*   Updated: 2021/09/25 18:23:58 by yassharm         ###   ########.fr       */
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
    char    **path;
    int     ret;
       
    ret = 0;
    if (argc != 5)
        return(clean_exit("Wrong arg please enter correct shit\n"));
    path = find_path(env);
    if (path == NULL)
        return(clean_exit("Path not found\nPlease try again\n") + 1);
    ret = start_pipex(argv, env, path);
    free_double_char(path);
    return (ret);   
}