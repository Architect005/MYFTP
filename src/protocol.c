/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** file transfer protocol
*/

#include "../include/my_ftp.h"

void protocol(manager *mng)
{
    FD_ZERO(&mng->readfds);
    FD_SET(mng->master_socket, &mng->readfds);
    mng->max_sd = mng->master_socket;
    mng->message = malloc(sizeof(1025));
    for (mng->x = 0; mng->x < mng->max_clients; mng->x++) {
        mng->sd = mng->client_socket[mng->x];
        if (mng->sd > 0)
            FD_SET(mng->sd, &mng->readfds);
        if (mng->sd > mng->max_sd)
            mng->max_sd = mng->sd;
    }
    mng->activity = select(mng->max_sd + 1, &mng->readfds, NULL, NULL,
                           NULL);
    if ((mng->activity < 0) && (errno != EINTR))
        printf("select error");
}
