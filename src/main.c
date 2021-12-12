/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "minishell.h"

char **check_builtins(char **buff, char **av, char **env)
{
    if (buff[0] == 0)
        return (NULL);
    if (my_strcmp(buff[0], "exit") == 0)
        exit(0);
    if (my_strcmp(buff[0], "cd") == 0)
        my_cd(buff, av, env);
    if (my_strcmp(buff[0], "env") == 0)
        my_env_disp(env);
    if (my_strcmp(buff[0], "setenv") == 0)
        return (my_setenv(env, buff));
    if (my_strcmp(buff[0], "unsetenv") == 0)
        return (my_unsetenv(env, buff[1]));
    return (env);
}

int is_builtin(char **buff)
{
    if (buff[0] == 0)
        return (0);
    if (my_strcmp(buff[0], "exit") == 0 ||
        my_strcmp(buff[0], "env") == 0 ||
        my_strcmp(buff[0], "setenv") == 0 ||
        my_strcmp(buff[0], "unsetenv") == 0 ||
        my_strcmp(buff[0], "cd") == 0)
        return (1);
    return (0);
}

int start_sh(char **av, char **env)
{
    char *buff;
    char **buffer;
    size_t len = 0;
    while (1) {
        if (isatty(0))
            my_printf("\033[36m$> \033[37m");
        if (getline(&buff, &len, stdin) == -1)
            return (84);
        buffer = my_str_to_word_array(buff);
        if (is_builtin(buffer) == 1)
            env = check_builtins(buffer, av, env);
        else
            path_handling(env, buff);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    start_sh(av, env);
    return (0);
}