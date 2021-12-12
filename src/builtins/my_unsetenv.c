/*
** EPITECH PROJECT, 2021
** my_unsetenv.c
** File description:
** my_unsetenv
*/

#include "minishell.h"

char **remove_env(char **env, char *buff, int i)
{
    while (env[i]) {
        env[i] = env[i + 1];
        i++;
    }
    env[i] = 0;
    return (env);
}

char **my_unsetenv(char **env, char *buff)
{
    int i = 0;
    int j = 0;

    if (buff == 0) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (env);
    }
    while (env[i] != 0) {
        for (j = 0; env[i][j] != '=' && env[i][j] != '\0'; j++);
        if (my_strncmp(env[i], buff, j) == 0) {
            return (remove_env(env, buff, i));
        }
        i++;
    }
    return (env);
}