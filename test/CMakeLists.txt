Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.0.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(VMathTest Vec3Test.cpp)
target_link_libraries(VMathTest PUBLIC VMath PRIVATE Catch2::Catch2WithMain)
target_include_directories(VMathTest PUBLIC VMath)