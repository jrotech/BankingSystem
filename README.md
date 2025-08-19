# BankingSystem (Under Development)

A simple C++23 banking simulation demonstrating accounts, transactions (deposit, withdraw, transfer), and basic interest application. The system tracks each operation via polymorphic transaction types.

## Features (current)
- Account management via [`Account`](include/Account.hpp)
- Bank container / lookup via [`Bank`](include/Bank.hpp)
- Polymorphic transaction hierarchy:
  - Base [`Transaction`](include/Transaction.hpp)
  - [`DepositTransaction`](include/DepositTransaction.hpp)
  - [`WithdrawTransaction`](include/WithdrawTransaction.hpp)
  - [`TransferTransaction`](include/TransferTransaction.hpp)
- Interest application (`[`Account::applyInterest`](src/Account.cpp)`)
- Basic validation for overdraft, invalid transfers
- Sequential transaction IDs (see constructor in [`Transaction`](src/Transaction.cpp))

## Project Structure
```
.
├── Makefile
├── include/
│   ├── Account.hpp
│   ├── Bank.hpp
│   ├── Transaction.hpp
│   ├── DepositTransaction.hpp
│   ├── WithdrawTransaction.hpp
│   └── TransferTransaction.hpp
├── src/
│   ├── Account.cpp
│   ├── Bank.cpp
│   ├── Transaction.cpp
│   ├── DepositTransaction.cpp
│   ├── WithdrawTransaction.cpp
│   ├── TransferTransaction.cpp
│   └── main.cpp
```

## Build
Requires g++ with C++23 support (Makefile uses `-std=c++23`).

```
make
```

Produces executable: `banking_app` (or `banking_app.exe` on Windows).

Clean:
```
make clean
```

## Run
```
./banking_app
```

The demo scenario is in [`src/main.cpp`](src/main.cpp).

## Key Classes / Methods
- [`Account::deposit`](include/Account.hpp) / implementation ([`Account.cpp`](src/Account.cpp))
- [`Account::withdraw`](include/Account.hpp)
- [`Account::transfer`](include/Account.hpp) (uses [`Bank::getAccountByNumber`](src/Bank.cpp))
- [`Account::applyInterest`](include/Account.hpp)
- [`Account::addTransaction`](include/Account.hpp)
- [`Transaction::getID`](src/Transaction.cpp), [`Transaction::getAmount`](src/Transaction.cpp), [`Transaction::getTimestamp`](src/Transaction.cpp)

## Example (from main)
Creating accounts and performing operations (see [`src/main.cpp`](src/main.cpp)).

## Development Status
In-progress. Current limitations:
- No persistence (in-memory only)
- No input validation beyond simple checks
- No reporting / transaction history viewer
- No unit tests yet

## Planned Enhancements
- Transaction history printing (iterate stored `transactions` in [`Account`](include/Account.hpp))
- Export / serialization
- Input-driven CLI
- Interest compounding strategies
- Error handling improvements (replace console prints with status codes / exceptions)