/*
** EPITECH PROJECT, 2022
** print_line.c
** File description:
** fghjkl
*/

#include "../include/my_ftp.h"

void cmd_quit(manager *mng)
{
    if (strncasecmp(mng->buffer, "QUIT\r", 5) == 0) {
        write(mng->new_socket, "221 Service closing control connection.\r\n", 37);
        write(mng->new_socket, "Logged out if appropriate.\r\n", 28);
        close(mng->new_socket);
    }
}
