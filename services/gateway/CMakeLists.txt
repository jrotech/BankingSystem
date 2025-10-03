add_executable(gateway src/main.cpp)
target_link_libraries(gateway PRIVATE core fmt::fmt spdlog::spdlog)
set_target_properties(gateway PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
