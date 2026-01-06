#pragma once

// Mount filesystem from disk
// Returns 0 on success, -1 on failure
int fs_mount();

// Unmount filesystem
void fs_unmount();
