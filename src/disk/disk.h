#pragma once
#include <cstdint>

// Fixed block size for the entire filesystem
constexpr uint32_t BLOCK_SIZE = 4096;

// Initialize disk backing file
// Returns 0 on success, -1 on failure
int disk_init(const char* path);

// Read exactly one block into buf
int disk_read(uint32_t block_no, void* buf);

// Write exactly one block from buf
int disk_write(uint32_t block_no, const void* buf);

// Shutdown disk
void disk_close();
