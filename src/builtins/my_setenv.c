/*
** EPITECH PROJECT, 2021
** builtins.c
** File description:
** builtins
*/

#include "minishell.h"

char **add_env(char **env, char **av)
{
    int i = 0;
    char **new_env = malloc(sizeof(char *) * 1000);

    while (env[i] != 0) {
        new_env[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 2));
        new_env[i] = env[i];
        i++;
    }
    new_env[i] = my_strcat(av[1], "=");
    if (av[2] != 0)
        new_env[i] = my_strcat(new_env[i], av[2]);
    return (new_env);
}

char **my_setenv(char **env, char **av)
{
    if (av[1] == 0) {
        my_env_disp(env);
        return (env);
    }
    if (my_str_isalpha(av[1]) != 1 && my_str_isnum(av[1]) != 1) {
        my_puterror("setenv: Variable name must contain alphanumeric \
characters.\n");
        return (env);
    }
    if (av[1][0] <= 64 || (av[1][0] >= 91 && av[1][0] <= 96) || \
av[1][0] >= 123) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return (env);
    }
    return (add_env(env, av));
}
