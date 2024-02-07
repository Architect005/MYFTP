/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** file protocol transfer
*/

#include "../include/my_ftp.h"

void check(manager *mng)
{
    if (strncasecmp(mng->buffer, "PASS\r\n", 4) == 0) {
        if (mng->y == 0)
            write(mng->sd, "332 need an account first\n", 26);
        else if (mng->y == 1 && (mng->buffer[6] == '\0')) {
            write(mng->sd, "230 password correct\n", 21);
            mng->y = 3;
        }
        else
            write(mng->sd, "530 password incorrect\n", 23);
    }
}
