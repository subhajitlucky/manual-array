# Manual Array 

This project is a hands-on exercise to implement and test manual array operations in C++. It covers fixed-size arrays, dynamic arrays, and advanced memory management techniques. The goal is to build a deeper understanding of arrays, pointers, and memory handling in C++.

---

## Prerequisites

- **Compiler**: Ensure you have `g++` installed (supports C++17 or later).
- **Optional Tools**:
  - [Valgrind](https://valgrind.org/) for memory leak detection.
  - AddressSanitizer (enabled via compiler flags) for runtime memory checks.

---

## Files (implement these in order)

1. `01_fixed_size_array.cpp` — fixed-size array basics: declare `int arr[5]`, print values and addresses.
2. `02_access_with_pointers.cpp` — access array via `arr[i]` and `*(arr + i)` and compare.
3. `03_array_in_struct.cpp` — struct with `int data[10]; size_t size; size_t capacity;` and simple initialization.
4. `04_safe_indexing.cpp` — implement safe `at(int index)` with bounds checks and error messages.
5. `05_manual_push.cpp` — implement `push_back(int)` with capacity check (no resize yet).
6. `06_manual_pop.cpp` — implement `pop_back()` with empty-check handling.
7. `07_insert_erase_shift.cpp` — implement `insert(index, value)` and `erase(index)` performing manual shifts.
8. `08_resize_array.cpp` — implement resizing by creating a larger fixed array and copying values.
9. `09_resize_with_heap.cpp` — implement heap-based resize with `new[]` and `delete[]`.
10. `10_wrap_in_struct.cpp` — `DynamicArray` struct with ctor/dtor managing heap memory.
11. `11_rule_of_three.cpp` — implement copy ctor, copy assignment, and destructor (rule of three).
12. `12_move_semantics.cpp` — implement move ctor and move assignment.
13. `13_generic_dynamic_array.cpp` — template or `void*`+`elem_size` generic dynamic array.
14. `14_shrink_to_fit.cpp` — implement shrink-to-fit that releases unused capacity.
15. `15_iterator_support.cpp` — provide `begin()`/`end()` pointers for range-based for loops.
16. `16_alignment_and_padding.cpp` — experiments showing `sizeof` and member addresses to study padding.

---

## How to use

- Open a file, implement the functions and test cases described in the checklist.
- Compile individual `.cpp` files with `g++ -std=c++17 -O2 -Wall <file>` while you work on them.

---

## Notes

- Keep tests small and self-contained in each `.cpp` file (a `main()` that demonstrates the feature).
- When you start implementing heap allocation and move/copy semantics, run tools like Valgrind (or AddressSanitizer) to check for leaks.

---

## Contributing

- Fork the repository and create a new branch for your changes.
- Follow the checklist and ensure your code is well-documented.
- Run tests and check for memory leaks before submitting a pull request.

---

Happy coding — ping me if you want me to implement any of these files for you or add a build/test harness (CMake / Makefile / unit tests).
