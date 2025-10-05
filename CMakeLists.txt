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

# Sanitizers (Clang/GCC) ----
option(ENABLE_ASAN "Enable AddressSanitizer" OFF)
option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer" OFF)

set(_san_list "")
if (ENABLE_ASAN)
  list(APPEND _san_list "address")
endif()
if (ENABLE_UBSAN)
  list(APPEND _san_list "undefined")
endif()

if (_san_list)
  string(JOIN "," _san_joined ${_san_list})
  add_compile_options(-fsanitize=${_san_joined} -fno-omit-frame-pointer)
  add_link_options(-fsanitize=${_san_joined})
  add_compile_options(-fno-sanitize-recover=undefined)
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
