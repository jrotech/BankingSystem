# Coding Standards

- C++20+ (move to C++23 as toolchains allow).
- ClangFormat enforced; lint via clang-tidy (see .clang-format/.clang-tidy).
- No raw `new`/`delete` in services; prefer RAII and `std::unique_ptr`/`std::shared_ptr` as justified.
- Errors: use `expected<T,E>`-style or exceptions at boundaries; no bare `assert` for validation.
- Logging via spdlog; no `std::cout` in library code.
- Public headers under `core/include`; service headers under `services/<svc>/include`.
- Tests: GTest; name tests `*_test.cpp`; aim for fast, deterministic unit tests.
