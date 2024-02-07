/*
** EPITECH PROJECT, 2022
** first_part.c
** File description:
** gdhdjh
*/

#include "../include/my_ftp.h"

void ftp(manager *mng, char **argv)
{
    for (mng->x = 0; mng->x < mng->max_clients; mng->x++) {
        mng->client_socket[mng->x] = 0;
    }
    if ((mng->master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(mng->master_socket, SOL_SOCKET, SO_REUSEADDR,
                   (char *)&mng->opt, sizeof(mng->opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    mng->address.sin_family = AF_INET;
    mng->address.sin_addr.s_addr = INADDR_ANY;
    mng->address.sin_port = htons(atoi(argv[1]));
    if (bind(mng->master_socket, (struct sockaddr *)&mng->address,
             sizeof(mng->address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
        if (listen(mng->master_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    mng->addrlen = sizeof(mng->address);
}
