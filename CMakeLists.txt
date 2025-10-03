cmake_minimum_required(VERSION 3.24)
project(BankingSystem LANGUAGES CXX)

option(BUILD_TESTS "Build tests" ON)
option(ENABLE_CLANG_TIDY "Enable clang-tidy" ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies (vcpkg provides CONFIG packages)
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
if (BUILD_TESTS)
  find_package(GTest CONFIG REQUIRED)
endif()

# Enable clang-tidy if found (non-fatal if missing)
if (ENABLE_CLANG_TIDY)
  find_program(CLANG_TIDY_EXE NAMES clang-tidy)
  if (CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
  endif()
endif()

# Warnings-as-errors (clang/gcc)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_subdirectory(core)
add_subdirectory(services/gateway)    # simple demo
if (BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
