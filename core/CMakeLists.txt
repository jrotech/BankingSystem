add_library(core STATIC
  src/Account.cpp
  src/Bank.cpp
  src/Transaction.cpp
  src/TransferTransaction.cpp
  src/WithdrawalTransaction.cpp
  src/DepositTransaction.cpp
)

target_include_directories(core PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(core PUBLIC fmt::fmt spdlog::spdlog)
