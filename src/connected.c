/*
** EPITECH PROJECT, 2022
** multico
** File description:
** multico
*/

#include "../include/my_ftp.h"

void connected(manager *mng, char **argv)
{
    while (TRUE) {
        protocol(mng);
        if (FD_ISSET(mng->master_socket, &mng->readfds)) {
            if ((mng->new_socket = accept(mng->master_socket,
                                          (struct sockaddr *)&mng->address,
                                          (socklen_t *)&mng->addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE); }
            write(mng->new_socket, "220 Service ready for new user.\n", 32);
            for (mng->x = 0; mng->x < mng->max_clients; mng->x++) {
                if (mng->client_socket[mng->x] == 0) {
                    mng->client_socket[mng->x] = mng->new_socket;
                }
            }
        }
        disconnected(mng, argv);
    }
}
