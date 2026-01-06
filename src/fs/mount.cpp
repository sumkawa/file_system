#include "fs.h"
#include "superblock.h"
#include "../disk/disk.h"
#include <cstdio>

static Superblock sb;

int fs_mount() {
    // TODO:
    // - read superblock from block 0
    // - validate magic
    // - validate layout sanity
    // - store global state
    //
    // If ANY invariant fails:
    //   return -1


    return -1;
}

void fs_unmount() {
    // TODO:
    // - flush state if needed
}
