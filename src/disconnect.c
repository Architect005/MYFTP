/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** file transfer protocol
*/

#include "../include/my_ftp.h"

void disconnected(manager *mng, char **argv)
{
    for (mng->x = 0; mng->x < mng->max_clients; mng->x++) {
        mng->sd = mng->client_socket[mng->x];
        if (FD_ISSET(mng->sd, &mng->readfds)) {
            if ((mng->valread = read(mng->sd, mng->buffer, 1024)) == 0) {
                getpeername(mng->sd, (struct sockaddr *)&mng->address,
                            (socklen_t *)&mng->addrlen);
                printf("Host disconnected, ip %s, port %d \n",
                       inet_ntoa(mng->address.sin_addr), ntohs(mng->address.sin_port));
                mng->client_socket[mng->x] = 0;
            }
            for (int u = 0; mng->buffer[u] != '\0'; u++) {
                if (mng->buffer[u] == '\n') {
                    mng->buffer[u] = '\0';
                    break; }
            }
            cmd_quit(mng);
            cmd_help(mng);
            cmd_noop(mng);
            location(mng, argv);
            user(mng);
            check(mng);
        }
    }
}
