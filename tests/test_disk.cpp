#include "disk.h"
#include <cstdio>
#include <cstring>

#define TEST_DISK_FILE "testdisk.img"

int main() {
    if (disk_init(TEST_DISK_FILE) != 0) {
        return 1;
    }

    char write_buf[BLOCK_SIZE];
    for (int i = 0; i < BLOCK_SIZE; i++) {
        write_buf[i] = i % 256;
    }

    if (disk_write(0, write_buf) != 0) {
        printf("disk_write failed\n");
        disk_close();
        return 1;
    }

    char read_buf[BLOCK_SIZE];
    memset(read_buf, 0, BLOCK_SIZE);

    if (disk_read(0, read_buf) != 0) {
        printf("disk_read failed\n");
        disk_close();
        return 1;
    }

    if (memcmp(write_buf, read_buf, BLOCK_SIZE) == 0) {
        printf("Block read/write successful!\n");
    } else {
        printf("Data mismatch!\n");
    }

    disk_close();
    return 0;
}
