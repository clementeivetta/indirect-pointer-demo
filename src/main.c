#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "indirect.h"

#define FILENAME "archivo"
#define BLOCKS_TO_WRITE 17

int main(void) {
    int fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("Writing blocks to '%s'...\n\n", FILENAME);


    for (int i = 1; i <= BLOCKS_TO_WRITE; i++) {
        one_block_write(fd);
        
        long file_size = get_file_size(fd);
        long disk_usage = get_disk_usage(FILENAME);
        
        printf("+1 block written (iteration %d)\n", i);
        printf("File size: %ld bytes\n", file_size);
        printf("Disk usage: %ld bytes\n", disk_usage);
        printf("\n");
    }

    close(fd);
    printf("Done. File '%s' has been created.\n", FILENAME);
    printf("To see final disk usage, run: du -h %s\n", FILENAME);
    
    return 0;
}