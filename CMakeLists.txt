cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(libnoise VERSION 1.0.0.2)

# End-user variables
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build Type." FORCE)
set(BUILD_SHARED_LIBS TRUE CACHE BOOL "Build shared libraries.")
set(BUILD_DOC FALSE CACHE BOOL "Build Doxygen documentation.")
set(SKIP_INSTALL FALSE CACHE BOOL "Don't install libnoise.")

# Hide skipping install
mark_as_advanced(SKIP_INSTALL)

# Tell the project we're building it
add_definitions(-DNOISE_BUILD)

# Check if we're building shared or static
if(BUILD_SHARED_LIBS)
    set(LIB_TYPE SHARED)
    add_definitions(-DNOISE_SHARED_LIB)
else()
    set(LIB_TYPE STATIC)
endif()

# Set our source and include directories
set(SRC_DIR "src")
set(INC_DIR "include")
include_directories(${INC_DIR})

# Find our source files
file(GLOB SOURCES
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/model/*.cpp"
    "${SRC_DIR}/module/*.cpp"
    "${INC_DIR}/noise/*.h"
    "${INC_DIR}/noise/model/*.h"
    "${INC_DIR}/noise/module/*.h"
)

# Add the libnoise library
add_library(libnoise ${LIB_TYPE} ${SOURCES})
target_include_directories(libnoise PRIVATE "${INC_DIR}/noise")

# GCC will automatically add the prefix lib
if(CMAKE_COMPILER_IS_GNUCXX)
    set_target_properties(libnoise PROPERTIES OUTPUT_NAME noise)
endif()

# Build the documentation if we're told to
if(BUILD_DOC)
    add_subdirectory(doc)
endif()

# Install necessary files
if(NOT SKIP_INSTALL)
    install(
        TARGETS libnoise
        RUNTIME DESTINATION bin COMPONENT bin
        LIBRARY DESTINATION lib COMPONENT bin
        ARCHIVE DESTINATION lib COMPONENT dev
    )

    install(
        DIRECTORY include/noise/
        DESTINATION include/${LIBNOISE_INCLUDE_DIR_NAME}
    )
endif()
