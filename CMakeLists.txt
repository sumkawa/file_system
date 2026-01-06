cmake_minimum_required(VERSION 3.10)
project(MyFileSystem C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/util
    ${PROJECT_SOURCE_DIR}/src/disk
    ${PROJECT_SOURCE_DIR}/src/fs
)

# Filesystem library (disk + fs)
add_library(filesystem STATIC
    src/disk/disk.cpp
    src/fs/mount.cpp
)

# Main executable
add_executable(myfs
    src/main.cpp
    util/utils.c
)
target_link_libraries(myfs PRIVATE filesystem)

# Format tool (creates/formats disk images)
add_executable(format
    src/format.cpp
)
target_link_libraries(format PRIVATE filesystem)

# Add tests subdirectory
add_subdirectory(tests)
