#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "indirect.h"

void one_block_write(int fd) {
    // Write 4096 bytes; simple and deterministic
    for (unsigned int i = 0u; i < 4096u; i++) {
        if (write(fd, "a", 1) != 1) {
            perror("write");
            break;
        }
    }
}

long get_file_size(int fd) {
    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("fstat");
        return -1;
    }
    return (long)st.st_size;
}

long get_disk_usage(const char *filename) {
    struct stat st;
    if (stat(filename, &st) < 0) {
        perror("stat");
        return -1;
    }
    // st_blocks is in 512-byte blocks
    return (long)st.st_blocks * 512;
}

void print_disk_usage_command(const char *filename) {
    char command[256];
    snprintf(command, sizeof(command), "du -h %s", filename);
    system(command);
}
