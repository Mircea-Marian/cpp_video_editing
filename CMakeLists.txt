cmake_minimum_required(VERSION 3.10)

project(VideoStreamProcessor)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(video_processor src/main.cpp)

target_link_libraries(video_processor ${OpenCV_LIBS})

if(WIN32)
add_custom_command(TARGET video_processor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_RUNTIME_DLLS:video_processor>
    $<TARGET_FILE_DIR:video_processor>
    COMMAND_EXPAND_LISTS
)
endif()