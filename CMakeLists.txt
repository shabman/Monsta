cmake_minimum_required(VERSION 3.8)

project(Monsta)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE MONSTA_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE MONSTA_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

add_compile_definitions(GLEW_STATIC)

# Configure for Xcode
# if(APPLE)
# include_directories(SYSTEM ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})

# # Collect all source and header files
# file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
# file(GLOB_RECURSE HEADERS "include/*.h")

# foreach(FILE ${SOURCES} ${HEADERS})
# # Get the relative path of each file (relative to CMAKE_SOURCE_DIR)
# file(RELATIVE_PATH FILE_REL_PATH ${CMAKE_SOURCE_DIR} ${FILE})

# # Get the directory name of the file's relative path
# get_filename_component(FILE_GROUP_PATH ${FILE_REL_PATH} DIRECTORY)

# # Replace '/' with '\\' to be compatible with Xcode
# string(REPLACE "/" "\\" GROUP_NAME ${FILE_GROUP_PATH})

# # Group files in their respective folders
# source_group("${GROUP_NAME}" FILES ${FILE})
# endforeach()

# # Add executable or library target
# # add_executable(MonstaDemo ${SOURCES} ${HEADERS})
# endif()

if(WIN32)
    file(GLOB_RECURSE MONSTA_LIBS_DEBUG CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/Windows/debug/*.lib")
    file(GLOB_RECURSE MONSTA_LIBS_RELEASE CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/Windows/release/*.lib")
    source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${MONSTA_SOURCES} ${MONSTA_HEADERS})
elseif(APPLE)
    file(GLOB_RECURSE MONSTA_LIBS_DEBUG CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/Apple/debug/*.a")
    file(GLOB_RECURSE MONSTA_LIBS_RELEASE CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/Apple/release/*.a")
endif()

add_executable(MonstaDemo "${MONSTA_SOURCES}" "${MONSTA_HEADERS}")

link_directories(lib)

find_package(OpenGL REQUIRED)

if(APPLE)
    find_library(COREAUDIO_FRAMEWORK CoreAudio)
    find_package(OpenAL REQUIRED)
endif()

target_include_directories(MonstaDemo PUBLIC ${OPENGL_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(MonstaDemo "${OPENGL_LIBRARIES}" "${MONSTA_LIBS_DEBUG}")

if(WIN32)
    set_property(TARGET MonstaDemo PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/asset")
elseif(LINUX)
    find_package(GLEW REQUIRED)
    find_package(glfw3 3.4 REQUIRED)
    target_link_libraries(MonstaDemo GLEW::GLEW glfw)
elseif(APPLE)
    target_link_libraries(MonstaDemo "-framework CoreServices -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework OpenAL" ${OPENAL_LIBRARY})
endif()
