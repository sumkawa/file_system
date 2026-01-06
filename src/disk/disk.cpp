#include "disk.h"
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <sys/stat.h>
#include <cstring>
#include <cerrno>

static int disk_fd = -1;

int disk_init(const char* path) {
    // TODO:
    // - open file
    // - store fd
    // - handle errors
    if (disk_fd != -1) {
        fprintf(stderr, "disk initialized already\n");
        return -1;
    }

    disk_fd = open(path, O_RDWR | O_CREAT, 0644);
    if (disk_fd < 0) {
        perror("open");
        return -1;
    }
    return 0;
}

int disk_read(uint32_t block_no, void* buf) {
    // TODO:
    // - seek to block_no * BLOCK_SIZE
    // - read BLOCK_SIZE bytes
    // - handle partial reads
    size_t seek = block_no * BLOCK_SIZE;
    off_t ret = lseek(disk_fd, seek, SEEK_SET);
    if (ret == -1) {
        perror("lseek failed");
        return -1;
    }
    size_t bytesRead = 0;
    while (bytesRead < BLOCK_SIZE) {
        ssize_t numBytes = read(disk_fd, (char *)buf + bytesRead, BLOCK_SIZE - bytesRead);
        if (numBytes < 0) {
            perror("read failed");
            return -1;
        }
        if (numBytes == 0) {
            break;
        }
        bytesRead += numBytes;
    }

    return 0;
}

int disk_write(uint32_t block_no, const void* buf) {
    // TODO:
    // - seek
    // - write BLOCK_SIZE bytes
    // - fsync?

    size_t seek = block_no * BLOCK_SIZE;
    off_t ret = lseek(disk_fd, seek, SEEK_SET);
    if (ret == -1) {
        perror("seek failed");
        return -1;
    }
    size_t bytesWritten = 0;
    while (bytesWritten < BLOCK_SIZE) {
        ssize_t numBytes = write(disk_fd, (char *)buf + bytesWritten, BLOCK_SIZE - bytesWritten);
        if (numBytes == 0) {
            break;
        }
        if (numBytes == -1) {
            perror("write failed");
            return -1;
        }
        bytesWritten += numBytes;
    }
    int sync_status = fsync(disk_fd);
    if (sync_status == -1) {
        perror("sync failed");
        return -1;
    }
    return 0;
}

void disk_close() {
    if (disk_fd != -1) {
        if (close(disk_fd) == -1) {
            perror("close failed");
        }
        disk_fd = -1;
    }
}
