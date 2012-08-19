# Build the main executable. 
add_executable(${PROJECT_NAME} ${MAIN_SOURCE} ${PROJECT_SOURCES})

# Compiler flags for the standard build should be placed here.
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")

# Set the directory for "make install" to place the binary file.
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/bin)
