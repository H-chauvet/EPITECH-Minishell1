/*
** EPITECH PROJECT, 2020
** Minishell.h
** File description:
** MINISHELL header
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include "my.h"
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>

int my_env_disp(char **env);
char **my_envcopy(char **env, int env_len);
int get_env_len(char **env);
int my_cd(char **buff, char **av, char **env);
char *path_handling(char **env, char *buffer);
void my_status(int status);
char **my_setenv(char **env, char **av);
char **add_env(char **env, char **av);
char **my_unsetenv(char **env, char *buff);
char *get_path(char **env);
char *get_homepath(char **env);
void exec_init(char **buffer, char **env, char *str);

#endif /* !MINISHELL_H_ */
