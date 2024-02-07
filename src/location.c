/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** file protocol transfer
*/

#include "../include/my_ftp.h"

void location(manager *mng, char **argv)
{
    if (strncasecmp(mng->buffer, "PWD\r", 4) == 0) {
        if (mng->y == 3) {
            char *string = getcwd(argv[2], 500);
            write(mng->new_socket, "257", 4);
            write(mng->new_socket, string, strlen(string));
            write(mng->new_socket, "created.\r\n", 10);
        } else
            write(mng->sd, "530 need login\n", 15);
    }
}
