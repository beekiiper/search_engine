cmake_minimum_required(VERSION 3.24)

project(search_engine)
include(FetchContent)
FetchContent_Declare(
        googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(nlohmann_json)


add_executable(search_engine main.cpp
        src/ConverterJSON.cpp
        GoogleTests/tests.cpp
        src/InvertedIndex.cpp
        src/SearchServer.cpp
        GoogleTests/InvertedIndexTest.cpp
        GoogleTests/SearchServerTest.cpp
        include/InvertedIndex.h
        include/SearchServer.h
        include/ConverterJSON.h)


target_include_directories(search_engine PUBLIC include)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)




include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(gtest_disable_pthreads on)

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()


target_link_libraries(search_engine PRIVATE gtest gtest_main)
include(GoogleTest)
gtest_discover_tests(search_engine)