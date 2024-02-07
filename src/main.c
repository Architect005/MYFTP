/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** create ftp server
*/

#include "../include/my_ftp.h"

int help(void) {
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the Anonymous user\n");
    return (0);
}

int main(int ac, char **av) {
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        help();
    }
    else if (ac == 3) {
        DIR *dir_name = opendir(av[2]);
        if (atoi(av[1]) < 0 || atoi(av[1]) > 65535)
            return 84;
        if (!dir_name)
            return 84;

        manager *mng = malloc(sizeof(manager));
        mng->max_clients = 30;
        mng->opt = 1;
        mng->client_socket = malloc(sizeof(int) * (mng->max_clients+1));
        ftp(mng, av);
        connected(mng, av);
    }
    else
        return (84);
    return (0);
}
