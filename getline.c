#include "shell.h"

char *ourOwn_shellgetline(void) {
    static char buffer[BUFFER_SIZE];
    static int placed = 0;
    static int cmdbytes = 0;

    char *lineptr = NULL;
    int length_l = 0;
    char placeChar;

    while (1) {
        if (placed == cmdbytes) {
            cmdbytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (cmdbytes <= 0) {
                if (length_l == 0) {
                    return NULL;
                } else {
                    break;
                }
            }
            placed = 0;
        }

        placeChar = buffer[placed++];

        if (placeChar == '\n' || placeChar == EOF) {
            break;
        }

        if (length_l == 0) {
            lineptr = (char *)malloc(BUFFER_SIZE);
        } else if (length_l % BUFFER_SIZE == 0) {
            lineptr = (char *)realloc(lineptr, length_l + BUFFER_SIZE);
        }

        lineptr[length_l++] = placeChar;

        putchar(placeChar);
        fflush(stdout);
    }

    if (lineptr == NULL && length_l == 0) {
        return NULL;
    }

    if (length_l % BUFFER_SIZE == 0) {
        lineptr = (char *)realloc(lineptr, length_l + 1);
    }

    lineptr[length_l] = '\0';
    shell_print("\n");
    return lineptr;
}
