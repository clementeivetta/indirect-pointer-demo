Here are the contents for the file `/indirect-pointer-demo/indirect-pointer-demo/src/main.c`:

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "indirect.h"

int main(void) {
    int fd = open("archivo", O_WRONLY | O_APPEND | O_CREAT | S_IRWXU);
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }

    for (unsigned int i = 0u; i < 17u; i++) {
        one_block_write(fd);
        puts("+1 block written");

        if (i == 15u)
            puts("indirect pointer is about to be used");

        sleep(1);
    }

    close(fd);
    return 0;
}