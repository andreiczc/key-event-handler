cmake_minimum_required(VERSION 3.5...3.16)

project(key_event_handler   VERSION 0.1
                            LANGUAGES CXX)

set(LIBRARY_OUTPUT_PATH  "${CMAKE_SOURCE_DIR}/exe")
set(EXECUTABLE_OUTPUT_PATH  "${CMAKE_SOURCE_DIR}/exe")

add_subdirectory("./src")

add_executable(key_event_handler)
target_compile_features(key_event_handler PUBLIC cxx_std_17)
target_sources(key_event_handler
        PRIVATE     main.cpp)
target_link_libraries(key_event_handler
        key_press_watcher)

