cmake_minimum_required(VERSION 3.10)
project(CaptionPlayer)


include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
FetchContent_MakeAvailable(json)


add_executable(CaptionPlayer play_captions.cpp)
target_link_libraries(CaptionPlayer PRIVATE nlohmann_json::nlohmann_json)
