/*
** EPITECH PROJECT, 2021
** builtins.c
** File description:
** builtins
*/

#include "minishell.h"

int get_env_len(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return (i);
}

char **my_envcopy(char **env, int env_len)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * (env_len + 1));

    while (env[i] != NULL) {
        new_env[i] = my_strdup(env[i]);
        i++;
    }
    new_env[i] = NULL;
    return (new_env);
}

int my_env_disp(char **env)
{
    int env_len = get_env_len(env);
    int i = 0;
    char **my_env = my_envcopy(env, env_len);

    while (env[i] != NULL) {
        my_printf("%s\n", my_env[i]);
        i++;
    }
    return (0);
}
