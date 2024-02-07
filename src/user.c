/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** file protocol transfer
*/

#include "../include/my_ftp.h"

void user(manager *mng)
{
    if (strncasecmp(mng->buffer, "USER", 4) == 0) {
        if (strncasecmp(&mng->buffer[5], "ANONYMOUS\r", 10) == 0) {
            write(mng->sd, "331 username correct\n", 21);
            mng->y = 1;
        } else if (strncasecmp(&mng->buffer[5], "ANONYMOUS\r", 10) != 0) {
            write(mng->sd, "331 username has been given, need password\n", 43);
            mng->y = 2;
        }
    }
}
