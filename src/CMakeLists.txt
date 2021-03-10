cmake_minimum_required(VERSION 3.5...3.16)

project(key_press_watcher   VERSION 0.1
        LANGUAGES CXX)

add_library(key_press_watcher SHARED)

target_compile_definitions(key_press_watcher
        PRIVATE     mKEY_PRESS_WATCHER=1)

target_compile_features(key_press_watcher PUBLIC cxx_std_17)

target_sources(key_press_watcher
        PRIVATE     key_press_watcher.cpp
                    clickable.cpp
                    key_press_event.cpp)