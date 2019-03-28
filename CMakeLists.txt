cmake_minimum_required(VERSION 3.5)
project(vector LANGUAGES C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

include(git)

#Targets
set(SRCS src/vector.c src/memory.c)
add_library(vector-headers INTERFACE)
target_include_directories(vector-headers INTERFACE
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

# Shared
add_library(vector-shared SHARED ${SRCS})
target_link_libraries(vector-shared PUBLIC vector-headers)

# Static
add_library(vector-static STATIC ${SRCS})
target_link_libraries(vector-static PUBLIC vector-headers)

#Tests
include(test)

#Install
install(TARGETS vector-headers vector-static vector-shared
	EXPORT vectorTargets
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)
install(DIRECTORY include/vector DESTINATION include)

install(EXPORT vectorTargets
	FILE vectorTargets.cmake
	NAMESPACE vector::
	DESTINATION lib/cmake/vector
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("vectorConfigVersion.cmake"
	VERSION ${vector_VERSION}
	COMPATIBILITY SameMajorVersion
)

install(
	FILES
		"cmake/vectorConfig.cmake"
		"${CMAKE_CURRENT_BINARY_DIR}/vectorConfigVersion.cmake"
	DESTINATION
		lib/cmake/vector
)

#CPack
include(pack)
