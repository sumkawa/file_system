#pragma once
#include <cstdint>

constexpr uint32_t INODE_DIRECT_PTRS = 8;

enum class InodeType : uint16_t {
    FILE = 1,
    DIR  = 2
};

struct Inode {
    InodeType type;
    uint16_t  links;
    uint32_t  size;
    uint32_t  direct[INODE_DIRECT_PTRS];
};
