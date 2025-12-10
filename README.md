# Indirect Pointer Demo

Writes consecutive 4KiB blocks to a file and demonstrates the difference between file size and disk usage when indirect pointers are allocated in the filesystem.

## Purpose

This demo shows that when a file grows beyond what can be addressed by direct pointers in an inode, the filesystem allocates an indirect pointer block. This causes the disk usage to increase more than just the 4KiB of data written.

## Build and run
```bash
make
./indirect_pointer_demo
```

## What to look for

- **File size** increases by exactly 4096 bytes (4 KiB) with each write
- **Disk usage** usually increases by 4 KiB, BUT when an indirect pointer block is allocated, it jumps by 8 KiB or more
- Around iteration 12-13, you'll see: ">>> INDIRECT POINTER ALLOCATED! Disk usage increased by X bytes <<<"
- The program shows both programmatic disk usage and `du -h` output for verification

## Output example
```
Writing blocks to 'archivo'...

+1 block written (iteration 1)
File size: 4096 bytes (4 KiB)
Disk usage: 4096 bytes (4 KiB)
du -h output: 4.0K	archivo

+1 block written (iteration 2)
File size: 8192 bytes (8 KiB)
Disk usage: 8192 bytes (8 KiB)
du -h output: 8.0K	archivo

...

+1 block written (iteration 13)
File size: 53248 bytes (52 KiB)
Disk usage: 61440 bytes (60 KiB)
du -h output: 60K	archivo
>>> INDIRECT POINTER ALLOCATED! Disk usage increased by 8192 bytes <<<
```

## Understanding the output

- **File size**: The actual data stored (always increases by 4 KiB)
- **Disk usage**: Physical space occupied on disk (includes metadata blocks)
- When the indirect pointer block is allocated, disk usage increases by more than 4 KiB because the filesystem needs an additional block to store the indirect pointers

## Notes
- The demo writes to `archivo` in the current directory
- Remove `archivo` to start fresh:
  ```bash
  rm -f archivo
  ```
- The exact iteration where indirect pointers are used depends on the filesystem (HFS+, APFS, ext4, etc.)
- License: MIT
