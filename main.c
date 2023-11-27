#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int     main(void)
{
        int     fd;
        char    *buffer;

        fd = open("fichier.txt", O_RDONLY);
        buffer = get_next_line(fd);
        printf("%s", buffer);
        while(buffer)
        {
                free(buffer);
                buffer = get_next_line(fd);
                printf("%s", buffer);
        }
        close(fd);
        return (0);
}
