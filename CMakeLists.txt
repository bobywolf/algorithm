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

# set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
# include(cmakes/DownloadProject.cmake)
# download_project(PROJ                googletest
#         GIT_REPOSITORY      https://github.com/google/googletest.git
#         GIT_TAG             release-1.8.0
#         ${UPDATE_DISCONNECTED_IF_AVAILABLE}
#         )
# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
# add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})


include_directories(include/)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(src/ SOURCE_FILES)
add_executable(LeetCode ${SOURCE_FILES})
target_link_libraries(LeetCode gtest gtest_main)