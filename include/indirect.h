#ifndef _INDIRECT_H_
#define _INDIRECT_H_

// Writes exactly one 4KiB block ('a' bytes) to the file descriptor.
void one_block_write(int fd);

// Returns current file size in bytes for the given file descriptor.
// Prints errors via perror and returns -1 on failure.
long get_file_size(int fd);
long get_disk_usage(const char *filename);
void print_disk_usage_command(const char *filename);

#endif