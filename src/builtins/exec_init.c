/*
** EPITECH PROJECT, 2021
** exec_init.c
** File description:
** exec
*/

#include "minishell.h"

void exec_init(char **buffer, char **env, char *str)
{
    if (execve(buffer[0], buffer, env) == -1) {
        if (errno == ENOEXEC) {
            write(2, buffer[0], my_strlen(str));
            write(2, ": Exec format error. Wrong Architecture.\n", 41);
        }
    }
}