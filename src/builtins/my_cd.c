/*
** EPITECH PROJECT, 2021
** my_cd.c
** File description:
** my_cd
*/

#include "minishell.h"

int my_cd(char **buff, char **av, char **env)
{
    struct stat s;

    if (buff[1] == 0 || buff[1][0] == '~') {
        chdir(get_homepath(env));
        return (0);
    }
    if (stat(buff[1], &s) == -1) {
        write(2, buff[1], my_strlen(buff[1]));
        write(2, ": No such file or directory.\n", 29);
        return (0);
    }
    if (access(buff[1], R_OK) != 0) {
        my_puterror(buff[1]);
        my_puterror(": Permission denied.\n");
    } else if (S_ISDIR(s.st_mode))
        chdir(buff[1]);
    else {
        write(2, buff[1], my_strlen(buff[1]));
        write(2, ": Not a directory.\n", 19);
    }
    return (0);
}