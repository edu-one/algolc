<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# algolc

LeetCode solutions in C++, Rust, and Python.

## Layout

```
problems/<id>-<slug>.md   ← problem statement (shared)
cpp/      ← C++20 solutions (Conan 2 + CMake + GoogleTest)
rust/     ← Rust solutions (Cargo workspace, one crate per problem)
python/   ← Python solutions (pytest + ruff)
scripts/  ← new_problem.py scaffold tool
anki/     ← Anki flashcards (yanki format)
```

## Add a new problem

```bash
# C++ only (default):
python scripts/new_problem.py 0042 trapping-rain-water

# With Rust and/or Python:
python scripts/new_problem.py 0042 trapping-rain-water --rust --python
```

## Build & test

### C++ (from `cpp/`)
```bash
# Install Conan + CMake (once):
pip install -r requirements.txt

conan install . -s build_type=Release --build=missing
cmake --preset conan-default
cmake --build --preset conan-release
ctest --preset conan-release
```

### Rust (from `rust/`)
```bash
cargo test
```

### Python (from `python/`)
```bash
python -m pytest
```
