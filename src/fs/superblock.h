#pragma once
#include <cstdint>

constexpr uint32_t FS_MAGIC = 0xF00DBABE;

struct Superblock {
    uint32_t magic;
    uint32_t total_blocks;
    uint32_t inode_table_start;
    uint32_t inode_count;
    uint32_t data_block_start;
};
