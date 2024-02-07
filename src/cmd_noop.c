/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** file transfer protocol
*/

#include "../include/my_ftp.h"

void cmd_noop(manager *mng) {
    if (strncasecmp(mng->buffer, "NOOP\r", 5) == 0) {
        if (mng->y == 3)
            write(mng->new_socket, "200 Command okay.\r\n", 19);
        else
            write(mng->sd, "530 need login\n", 15);
    }
}
