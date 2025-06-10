cmake_minimum_required(VERSION 3.14)
project(LeetCode)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0
)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# aux_source_directory(src/ SOURCE_FILES)
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")
add_executable(LeetCode ${SOURCE_FILES})
target_include_directories(LeetCode PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(LeetCode gtest gtest_main)