#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

#define BUFFER_SIZE 1024

extern char **environ;

/* Function prototypes */
char *Reading_function(void);
char **Spliting_function(char *buffer, char *delemiter);
int Executing_commd_function(char **array);
void Interactive_shell(void);
void CleanupAndExit(int signum);
char *_getenv(char *name);
char *Verifying_path_function(char *command);
int _putchar(char c);
int _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
char *_strdup(char *source);
int _strcmp(char *s1, char *s2);
char *_strchr(char *str, char c);
int _atoi(char *s);
char *Reading_from_stream(void);
void No_Interactive_shell(void);
int Executing_built_in(char **array);
int my_exit(char **array);
int my_env(char **args);
int _getchar(void);
ssize_t _getline(char **buffer, size_t *n, int fd);
int _fgetc(int fd);
void Error_printing(char **array);
char *_strtok(char *str, char *del);

#endif
