cmake_minimum_required(VERSION 3.5)
project(MergeSort_OpenGL_original)

# Start of CMAKE
message("{{ STARTING CMAKE")

# Linker flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Custom CMake modules, ones that are not included in CMake Find like SDL2
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

# Require SDL2
find_package(SDL2 REQUIRED)
if (SDL2_FOUND)
    message(STATUS "SDL2_INCLUDE_DIR: ${SDL2_INCLUDE_DIR}")
    message(STATUS "SDL2_LIBRARY: ${SDL2_LIBRARY}")

    # Link SDL2 library
    link_libraries(${SDL2_LIBRARY})
    message(STATUS "SDL2 LIBRARY successfully linked")
endif()

# Require OpenGL
find_package(OpenGL REQUIRED)
if (OpenGL_FOUND)
    message(STATUS "OpenGL_INCLUDE_DIR: ${OPENGL_INCLUDE_DIR}")
    message(STATUS "OpenGL_LIBRARIES: ${OPENGL_LIBRARIES}")

    # Link OpenGL library
    link_libraries(${OPENGL_LIBRARIES})
    message(STATUS "OPENGL LIBRARY successfully linked")
endif()

# Require GLEW
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    message(STATUS "GLEW_INCLUDE_DIRS: ${GLEW_INCLUDE_DIRS}")
    message(STATUS "GLEW_LIBRARIES: ${GLEW_LIBRARIES}")
    # Link GLEW library
    link_libraries(${GLEW_LIBRARIES})
    message(STATUS "GLEW LIBRARY successfully linked")
endif()

# Set all source files
set(SOURCE_FILES src/main.cpp src/camera.h src/cameraHandler.cpp src/meni.cpp src/mergesort.cpp src/mesh.cpp src/prozor.cpp src/randomArrayGenerator.h src/shader.cpp src/transform.h)

# Copy all needed resources to build directory (Debug, Release)
message(STATUS "Copying resources ..")
file(GLOB resDir res/kvadrat.vert res/kvadrat.frag)
file(COPY ${resDir} DESTINATION res)

# End of CMAKE
message("END CMAKE }}")

add_executable(MergeSort_OpenGL_original ${SOURCE_FILES})