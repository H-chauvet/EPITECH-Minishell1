/*
** EPITECH PROJECT, 2021
** search_home.c
** File description:
** search_home
*/

#include "minishell.h"

char *get_homepath(char **env)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *home = malloc(sizeof(char) * my_strlen(env[i] + 5) + 1);

    while (env[i++]) {
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M' \
&& env[i][3] == 'E' && env[i][4] == '=') {
            j = 5;
            while (env[i][j])
                home[k++] = env[i][j++];
            home[k] = 0;
            return (home);
        }
    }
    return (NULL);
}