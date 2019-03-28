#Testing
if(CMAKE_BUILD_TYPE MATCHES "Debug")
	enable_testing()
	add_subdirectory(${PROJECT_SOURCE_DIR}/test)
endif()
