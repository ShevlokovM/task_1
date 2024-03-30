cmake_minimum_required(VERSION 3.5)

project(task_1_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable(task_1_3
    main.cpp
    ParamExtractor.h
    ParamExtractor.cpp
    AppWorkPackage.h
    AppWorkPackage.cpp
    InputDataExtractor.h
    InputDataExtractor.cpp
    InputValidation.h
    InputValidation.cpp
    Handler.h
    Handler.cpp
    FinalConverter.h
    FinalConverter.cpp
    ResultWriter.h
    ResultWriter.cpp)

target_link_libraries(task_1_3 PRIVATE nlohmann_json::nlohmann_json)
