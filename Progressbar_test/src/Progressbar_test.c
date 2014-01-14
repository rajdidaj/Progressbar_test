/*
 ============================================================================
 Name        : Progressbar_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define TOKEN_DISPLAY_WIDTH     (16)

#define EXTERNAL_CODE_SEC_SIZE      (0x010000)
#define EXTERNAL_CODE_LAST_SEC      (0x0FFFFF)

const unsigned char blankline[]     = "                              ";
const unsigned char progressbar[]   = "[                            ]";

int main(void)
{
    unsigned char msg_index = 1;
    unsigned char progress[16];

    unsigned long int sector;

    memcpy(progress, progressbar, 16);



    for (sector = EXTERNAL_CODE_SEC_SIZE; sector < EXTERNAL_CODE_LAST_SEC; sector += EXTERNAL_CODE_SEC_SIZE)
    {




        msg_index = ((double)sector)/((double)EXTERNAL_CODE_LAST_SEC) * (TOKEN_DISPLAY_WIDTH - 3) + 1;

        //printf("msg_index: %d    i: %d    max: %d    i/max: %f\n", msg_index, i, max, (double)i/max);

        progress[msg_index] = '=';

        printf("%s\n", progress);
        Sleep(100);

    }



    return EXIT_SUCCESS;
}
