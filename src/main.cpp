#include "disk/disk.h"
#include "fs/fs.h"
#include <cstdio>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("usage: %s <disk.img>\n", argv[0]);
        return 1;
    }

    if (disk_init(argv[1]) != 0) {
        printf("disk init failed\n");
        return 1;
    }

    if (fs_mount() != 0) {
        printf("mount failed\n");
        return 1;
    }

    printf("filesystem mounted successfully\n");

    fs_unmount();
    disk_close();
    return 0;
}
