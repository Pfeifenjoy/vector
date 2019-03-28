message(STATUS "Testing enabled")

add_executable(test-vector vector.c)
target_link_libraries(test-vector PRIVATE vector-shared)
add_test(test-vector test-vector)
