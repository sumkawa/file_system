# Enable CTest
enable_testing()

# Disk test
add_executable(test_disk test_disk.cpp)
target_link_libraries(test_disk PRIVATE filesystem)
add_test(NAME DiskTest COMMAND test_disk)
