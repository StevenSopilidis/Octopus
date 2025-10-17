cmake_minimum_required(VERSION 3.19)

project("octopus" LANGUAGES CXX ASM)

find_package(PkgConfig REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)


include(CTest)

add_subdirectory("src")

if (BUILD_TESTING)
    # find_package(Catch2 CONFIG REQUIRED)
    # add_subdirectory("test")
endif()