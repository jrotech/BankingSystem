cmake_minimum_required(VERSION 3.24)
project(DistributedBanking LANGUAGES CXX)

# ---- Options ----
option(ENABLE_ASAN "Enable AddressSanitizer (where supported)" OFF)
option(ENABLE_UBSAN "Enable UndefinedBehaviorSanitizer (non-MSVC)" OFF)
option(ENABLE_CLANG_TIDY "Enable clang-tidy analysis" ON)
option(BUILD_TESTS "Build tests" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- vcpkg integration (pass in -DCMAKE_TOOLCHAIN_FILE=...) ----
# If you set VCPKG_ROOT env var, a common pattern is:
# cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake

# ---- Dependencies via find_package (vcpkg provides them) ----
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
if (BUILD_TESTS)
  find_package(GTest CONFIG REQUIRED)
endif()

# ---- Sanitizers ----
include(CheckCXXCompilerFlag)
if (ENABLE_ASAN)
  if (MSVC)
    # MSVC ASan (x64, Release/Debug); requires MSVC v16.9+
    add_compile_options(/fsanitize=address)
    add_link_options(/INCREMENTAL:NO)
  else()
    add_compile_options(-fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
  endif()
endif()

if (ENABLE_UBSAN AND NOT MSVC)
  add_compile_options(-fsanitize=undefined)
  add_link_options(-fsanitize=undefined)
endif()

# ---- Warnings ----
if (MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# ---- clang-tidy ----
if (ENABLE_CLANG_TIDY)
  find_program(CLANG_TIDY_EXE NAMES clang-tidy)
  if (CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
  endif()
endif()

# ---- Subdirs ----
add_subdirectory(core)
add_subdirectory(services/gateway)
if (BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
