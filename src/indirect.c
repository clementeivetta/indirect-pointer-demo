#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "indirect.h"

void one_block_write(int fd) {
    for (unsigned int i = 0u; i < 4096; i++) {
        write(fd, "a", 1);
    }
}

int main(void) {
    int fd = open("archivo", O_WRONLY | O_APPEND | O_CREAT | S_IRWXU);
    
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