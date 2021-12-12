/*
** EPITECH PROJECT, 2021
** get_path.c
** File description:
** get_path
*/

#include "minishell.h"

char *get_path(char **env)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *path = NULL;

    while (env[i]) {
        path = malloc(sizeof(char) * my_strlen(env[i] + 5) + 1);
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' \
&& env[i][3] == 'H' && env[i][4] == '=') {
            j = 5;
            while (env[i][j])
                path[k++] = env[i][j++];
            path[k] = 0;
            return (path);
        }
        i++;
    }
    return (NULL);
}