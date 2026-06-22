LeetCode solutions
===============================

A single Conan + CMake monorepo. Each problem is a self-contained folder under
`problems/` with its own header-only solution and its own tests/datasets. Adding
a problem needs **no** build-system edits.

# Layout
```
├── CMakeLists.txt          # auto-discovers problems/*
├── conanfile.py            # Conan package manager file
├── common/                 # shared header-only helpers (ListNode, ...)
├── scripts/new_problem.py  # scaffold a new problem folder
└── problems/
    └── <id>-<slug>/
        ├── solution.hpp    # namespace dv::lc { class Solution ... }
        └── test.cpp        # datasets + GoogleTest cases
```

# Dependencies are managed by Conan, install it first
```bash
pip install -r requirements.txt
```

# Build (all problems)
```bash
conan install . --build=missing
cmake --preset conan-default
cmake --build --preset conan-debug
```

# Run tests (all problems)
```bash
ctest --preset conan-debug
```

# Working on a single problem
Incremental builds only recompile what you touched. Build and run just one:
```bash
cmake --build --preset conan-debug --target p_0001_two_sum
ctest --preset conan-debug -R 0001
```

# Configure only a subset (optional, for cold builds once you have many)
`LC_ONLY` is a regex matched against problem folder names:
```bash
cmake --preset conan-default -DLC_ONLY=0001
```

# Add a new problem
```bash
python scripts/new_problem.py 0042 trapping-rain-water
```

>📝
> Conventions (layout, formatting, Conan recipe) follow the template
> https://github.com/edu-one/cpptest
