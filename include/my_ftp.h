/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** file transfer protocol
*/

#ifndef MY_FTP_
#define MY_FTP_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <netdb.h>
#include <dirent.h>

#define MAX 80
#define TRUE 1
#define FALSE 0
#define SA struct sockaddr

typedef struct node
{
    int value;
    struct node *next;
    int data;
} node;

typedef struct manager
{
    struct sockaddr_in address;
    int opt;
    int master_socket;
    int addrlen;
    int new_socket;
    int *client_socket;
    int max_clients;
    int activity;
    int x, y;
    int valread;
    int sd, max_sd;
    fd_set readfds;
    node *multi_talk;
    node *tmp;
    char *message;
    char buffer[1080];
} manager;

void ftp(manager *, char **);
void protocol(manager *);
void check(manager *);
void user(manager *);
void cmd_quit(manager *);
void cmd_noop(manager *);
void cmd_help(manager *);
void location(manager *, char **);
void disconnected(manager *, char **);
void connected(manager *, char **);

#endif
