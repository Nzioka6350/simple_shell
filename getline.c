#include "shell.h"
/*
 *
 *
 *
 *
 */
char *ourOwn_shellgetline(void) {
    static char bufbuf[BUFF_SIZE];
    static int placed = 0;
    static int cmdbytes = 0;

    char *lineptr = NULL;
    int length_l = 0;
    char placeChar;

    while (1) {
        if (placed == cmdbytes) {
            cmdbytes = read(STDIN_FILENO, bufbuf, BUFF_SIZE);
            if (cmdbytes <= 0) {
                if (length_l == 0) {
                    return NULL;
                } else {
                    break;
                }
            }
            placed = 0;
        }

        placeChar = bufbuf[placed++];

        if (placeChar == '\n' || placeChar == EOF) {
            break;
        }

        if (length_l == 0) {
            lineptr = (char *)malloc(BUFF_SIZE);
        } else if (length_l % BUFF_SIZE == 0) {
            lineptr = (char *)realloc(lineptr, length_l + BUFF_SIZE);
        }

        lineptr[length_l++] = placeChar;

        putchar(placeChar);
        fflush(stdout);
    }

    if (lineptr == NULL && length_l == 0) {
        return NULL;
    }

    if (length_l % BUFF_SIZE == 0) {
        lineptr = (char *)realloc(lineptr, length_l + 1);
    }

    lineptr[length_l] = '\0';
    shell_print("\n");
    return lineptr;
}
