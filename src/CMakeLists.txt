cmake_minimum_required (VERSION 3.24)

set(Src
        ConverterJSON.cpp
        SearchServer.cpp
        InvertedIndex.cpp
        main.cpp
        )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_executable(search-engine ${Src})

target_link_libraries(search-engine nlohmann_json::nlohmann_json)
target_include_directories(search-engine PUBLIC ${MY_INCLUDE_DIR})