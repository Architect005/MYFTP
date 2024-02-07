/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** file transfer protocol
*/

#include "../include/my_ftp.h"

void cmd_help(manager *mng) {
    if (strncasecmp(mng->buffer, "HELP\r", 5) == 0) {
        if (mng->y == 3) {
            write(mng->new_socket, "214 Help message.\r\n", 19);
            write(mng->new_socket, "On how to use the server or the meaning of a particular\r\n", 57);
            write(mng->new_socket, "non-standard command.  This reply is useful only to the\r\n", 57);
            write(mng->new_socket, "human user.\r\n", 13);
        } else
            write(mng->sd, "530 need login\n", 15);
    }
}
