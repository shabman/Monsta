cmake_minimum_required(VERSION 3.8)

project(Monsta)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE MONSTA_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE MONSTA_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")

add_compile_definitions(GLEW_STATIC)

if(WIN32)
    file(GLOB_RECURSE MONSTA_LIBS_DEBUG CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/Windows/debug/*.lib")
    file(GLOB_RECURSE MONSTA_LIBS_RELEASE CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/Windows/release/*.lib")
    source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${MONSTA_SOURCES} ${MONSTA_HEADERS})
elseif(APPLE)
    file(GLOB_RECURSE MONSTA_LIBS_DEBUG CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/Apple/debug/*.a")
    file(GLOB_RECURSE MONSTA_LIBS_RELEASE CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/lib/Apple/release/*.a")
endif()

add_executable(a "${MONSTA_SOURCES}" "${MONSTA_HEADERS}")

link_directories(lib)

find_package(OpenGL REQUIRED)

if(APPLE)
    find_library(COREAUDIO_FRAMEWORK CoreAudio)
    find_package(OpenAL REQUIRED)
endif()

target_include_directories(a PUBLIC ${OPENGL_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/include/")

target_link_libraries(a "${OPENGL_LIBRARIES}" "${MONSTA_LIBS_DEBUG}")

if(WIN32)
    set_property(TARGET a PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/asset")
elseif(LINUX)
    find_package(GLEW REQUIRED)
    find_package(glfw3 3.4 REQUIRED)
    target_link_libraries(a GLEW::GLEW glfw)
elseif(APPLE)
    target_link_libraries(a "-framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework OpenAL" ${OPENAL_LIBRARY})
endif()
