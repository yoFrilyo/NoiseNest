cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.24)
    cmake_policy(SET CMP0135 NEW)
endif()



# -- PROJECT --
set(EXECUTABLE_NAME noisenest)
set(SOURCE_FILES src/main.cpp)
project(${EXECUTABLE_NAME})



# -- DEPENDENCIES --
include(FetchContent)

# CLI11
set(CLI11_VERSION 2.3.2)
FetchContent_Declare(
    CLI11
    URL https://github.com/CLIUtils/CLI11/archive/refs/tags/v${CLI11_VERSION}.zip
    FIND_PACKAGE_ARGS ${CLI11_VERSION}
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(CLI11_BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(CLI11)



# -- ADD EXECUTABLE --
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} CLI11)
