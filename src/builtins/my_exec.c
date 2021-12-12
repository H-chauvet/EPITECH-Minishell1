/*
** EPITECH PROJECT, 2021
** my_exec.c
** File description:
** my_exec
*/

#include "minishell.h"

void my_status(int status)
{
    if (WTERMSIG(status)) {
        if (WTERMSIG(status) == 8)
            my_printf("Floating exception\n");
        else
            my_printf("%s\n", strsignal(WTERMSIG(status)));
    }
}

void no_command(char *str)
{
    my_puterror(str);
    my_puterror(": Command not found.\n");
}

char *exec_path(char *buffer, char **env)
{
    int i = 0;
    char *path = get_path(env);
    if (!path)
        return (NULL);
    char **path_arr = my_str_to_word_array(path);
    char *cmdpath = NULL;

    for (i = 0; path_arr[i]; i++) {
        cmdpath = my_strcat(my_strcat(path_arr[i], "/"), buffer);
        if (access(cmdpath, X_OK) == 0 && access(cmdpath, F_OK) == 0)
            return (cmdpath);
    }
    return (NULL);
}

int start_exec(char **buffer, char **env, char *str)
{
    int status;
    pid_t pid;
    status = 0;

    if (buffer[0] != NULL) {
        pid = fork();
        if (pid == 0) {
            exec_init(buffer, env, str);
            exit(1);
        }
        waitpid(pid, &status, 0);
        my_status(status);
    }
    return (0);
}

char *path_handling(char **env, char *buffer)
{
    buffer[my_strlen(buffer) - 1] = '\0';
    char **tab = my_str_to_word_array(buffer);
    char *fullpath = exec_path(tab[0], env);

    if (access(tab[0], X_OK) == 0 && access(tab[0], F_OK) == 0) {
        start_exec(tab, env, buffer);
        return (NULL);
    }
    fullpath = exec_path(tab[0], env);
    if (fullpath == NULL) {
        no_command(tab[0]);
        free(fullpath);
    } else {
        tab[0] = fullpath;
        start_exec(tab, env, buffer);
    }
    return (NULL);
}