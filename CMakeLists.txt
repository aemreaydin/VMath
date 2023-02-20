cmake_minimum_required(VERSION 3.24)
project(VMath)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

add_subdirectory(test)
add_subdirectory(VUtils)

add_library(VMath STATIC src/Vec3.cpp)
target_include_directories(VMath PUBLIC include)
target_include_directories(VMath PUBLIC VUtils/include)

option(ENABLE_GSL ON)
if (ENABLE_GSL)
    FetchContent_Declare(GSL
            GIT_REPOSITORY "https://github.com/microsoft/GSL"
            GIT_TAG "v4.0.0"
            GIT_SHALLOW ON
            )
    FetchContent_MakeAvailable(GSL)
    target_link_libraries(VMath PRIVATE Microsoft.GSL::GSL)
endif (ENABLE_GSL)