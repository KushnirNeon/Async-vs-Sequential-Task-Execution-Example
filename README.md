# Async vs Sequential Task Execution Example

This C++ program demonstrates the use of `std::async` to run a slow task concurrently with other quick tasks. It compares asynchronous and sequential execution by measuring total execution time.

---

## Features

- Uses `std::async` to run a long-running function (`slow`) concurrently  
- Runs several short tasks (`quick`) sequentially while the slow task executes  
- Uses `osyncstream` for thread-safe console output  
- Measures and prints total execution time  

---

## Requirements

- C++17 or higher (for `std::async`, `std::future`, `osyncstream`)  
- Standard C++ compiler (e.g., `g++`)  
