#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int    main(void)
{
    int        fd;
    char    *line;

    fd = open("fichier.txt", O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break ;
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}