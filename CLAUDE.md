# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

# Claude instructions for `algolc`

## Project layout

```
algolc/
  problems/<id>-<slug>/README.md   ← shared problem statement (browsable reference)
  cpp/
    CMakeLists.txt  conanfile.py  .clang-format  .cmake-format
    common/include/dv/lc.hpp
    problems/<id>-<slug>/{solution.hpp, test.cpp}
  rust/
    Cargo.toml (workspace)  rust-toolchain.toml  rustfmt.toml
    problems/<id>-<slug>/{Cargo.toml, src/lib.rs}
  python/
    pyproject.toml (pytest + ruff)
    problems/<id>-<slug>/{solution.py, test_solution.py, conftest.py}
  scripts/new_problem.py   ← polyglot scaffold (opt-in per language)
  anki/                    ← language-agnostic Anki cards
```

Auto-discovery is preserved for all three languages:
- C++: `file(GLOB ...)` in `cpp/CMakeLists.txt`
- Rust: workspace `members = ["problems/*"]` in `rust/Cargo.toml`
- Python: pytest recursive `test_*.py` discovery from `python/`

---

## Shared conventions

**Copyright header:** every source file (C++, CMake, Python, YAML, TOML) starts with the
canonical block. The authoritative text is in `scripts/new_problem.py` (`HEADER`).
Do not retype — copy verbatim:
```
/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */
```
For Python/TOML/YAML, use `#` comment style instead of `/* */`.

**Line endings:** LF only (`\n`). Never write CRLF. Applies to every file.

---

## C++ conventions

**Stack:** C++20 · Conan 2 · CMake ≥ 3.23 presets · GoogleTest 1.14 (`gtest::gtest`) · CTest.

**Namespace:** `dv::lc` — every solution lives inside `namespace dv::lc { ... }`.

**Header guards:** `DV_LC_<ID>_<SLUG>_HPP` — uppercase, no leading underscores.
Example: `0042-trapping-rain-water` → `DV_LC_0042_TRAPPING_RAIN_WATER_HPP`.

**Shared helpers:** `cpp/common/include/dv/lc.hpp`, included as `<dv/lc.hpp>`. Currently
provides `ListNode`. Prefer helpers from there over reinventing them in test files.

**Test style:** suite name = PascalCase slug (`MergeTwoLists`), helper functions in an
anonymous namespace. See `cpp/problems/0021-merge-two-sorted-lists/test.cpp` for the canonical example.

**Formatting:** `.clang-format` governs C++; `.cmake-format` governs CMake. Run `clang-format`
on every C++ file you touch.

---

## Rust conventions

**Crate per problem:** each problem is an independent Cargo crate under `rust/problems/`.
Crate package name: `p<id>-<slug>` (e.g., `p0042-trapping-rain-water`). The `p` prefix is
required because Rust identifiers cannot start with a digit.

**Solution structure:**
```rust
pub struct Solution;

impl Solution {
    pub fn method_name(...) -> ... {
        // implementation
    }
}
```

**Tests:** inline in `src/lib.rs` under `#[cfg(test)] mod tests`. No separate test file.

**Run:** `cd rust && cargo test` (whole workspace) or `cargo test -p p<id>-<slug>` (one problem).

**Formatting:** `rustfmt` — run `rustfmt` on every Rust file you touch.

---

## Python conventions

**Solution structure:** `class Solution` in `solution.py`. No imports beyond what the solution
needs. Use `from typing import List` etc. as needed.

**Tests:** `test_solution.py` using pytest. Import via `from solution import Solution`.
Each problem directory contains a `conftest.py` that ensures the local `solution.py` is found.

**Run:** `cd python && python -m pytest` (all problems) or `pytest problems/<id>-<slug>` (one problem).

**Lint/format:** `ruff` — run `ruff check .` and `ruff format .` from `python/`.

---

## Build & test commands

### C++ (run from `cpp/`)
```bash
# Install dependencies (once, or after conanfile.py changes)
conan install . -s build_type=Release --build=missing

# Configure CMake (re-run whenever a new problem folder appears)
cmake --preset conan-default

# Build + test a single problem
cmake --build --preset conan-release --target p_<id>_<slug>
ctest --preset conan-release -R <id>

# Build + test everything
cmake --build --preset conan-release
ctest --preset conan-release
```

Target name: `p_0042_trapping_rain_water` (underscores, not hyphens).

### Rust (run from `rust/`)
```bash
cargo test                          # whole workspace
cargo test -p p<id>-<slug>          # single problem
```

### Python (run from `python/`)
```bash
python -m pytest                    # all problems
pytest problems/<id>-<slug>         # single problem
ruff check .                        # lint
```

---

## Phase 1 — Problem setup

When the user says "set up problem N" or equivalent:

1. **Acquire the problem statement.**
   - If given a LeetCode URL, attempt `WebFetch`. If the fetch is thin or incomplete, ask the user to paste the statement.
   - If text is pasted directly, use it as-is.

2. **Scaffold the folder:**
   ```bash
   # C++ only (default):
   python scripts/new_problem.py <id> <slug>

   # C++ + Rust:
   python scripts/new_problem.py <id> <slug> --rust

   # C++ + Python:
   python scripts/new_problem.py <id> <slug> --python

   # All three:
   python scripts/new_problem.py <id> <slug> --rust --python

   # Add Rust to an existing problem (slug derived automatically):
   python scripts/new_problem.py <id> --rust
   ```
   For C++: also run `cd cpp && cmake --preset conan-default` to pick up the new folder.

3. **Write `problems/<id>-<slug>/README.md`** — the browsable GitHub reference:
   - Title + LeetCode URL
   - Difficulty (`Easy` / `Medium` / `Hard`)
   - Topics/tags (e.g., `Array`, `Hash Table`, `Two Pointers`)
   - Full problem statement
   - Constraints
   - Worked examples (input → output → explanation)
   - Target time and space complexity (derive from constraints; confirm with user if uncertain)

4. **Replace the placeholder tests** with real test cases:
   - **C++** (`cpp/problems/<id>-<slug>/test.cpp`): GoogleTest cases, all examples + edge cases.
     Follow the test style in `cpp/problems/0021-merge-two-sorted-lists/test.cpp`.
   - **Rust** (`rust/problems/<id>-<slug>/src/lib.rs`): `#[cfg(test)]` block, mirror the C++ cases.
   - **Python** (`python/problems/<id>-<slug>/test_solution.py`): pytest functions, mirror C++ cases.

5. **Do not fill in the solution.** Leave the TODO stub for the user to solve.

6. **Benchmarks** — opt-in only. Flag it and do it only if explicitly asked.

---

## Phase 2 — Interview coach (graduated hints)

When the user is working on a problem and asks for help:

- Default to the smallest useful nudge: a clarifying question or a single observation.
- Escalate only when the user asks for more:
  1. **Nudge** — point at the key insight without stating it ("what happens at the boundary?")
  2. **Approach** — name the technique/pattern at high level ("two-pointer scan")
  3. **Pseudocode + complexity** — outline the algorithm; state time/space complexity
  4. **Full solution** — only when the user explicitly says they want it

Stay in the user's chosen language and idioms. For Rust: reference ownership, iterators,
match patterns where relevant. For Python: reference list comprehensions, dicts, etc.

---

## Phase 3 — Solution review

When the user says they're done (or "review my solution"):

1. Read the solution file for the active language.
2. **Correctness** — trace through provided examples and edge cases; flag failures.
3. **Complexity** — state time and space complexity; compare to targets in `README.md`.
4. **Conventions** — check language-specific conventions (namespace/guards for C++,
   pub struct for Rust, class Solution for Python, copyright header, formatting).
5. **Build + test** — run the appropriate command:
   - C++: `cmake --build --preset conan-release --target p_<id>_<slug> && ctest --preset conan-release -R <id>`
   - Rust: `cargo test -p p<id>-<slug>` (from `rust/`)
   - Python: `pytest problems/<id>-<slug>` (from `python/`)
   Report results honestly; do not claim green if there are failures.
6. **Follow-ups** — ask 2–3 interviewer-style questions.
7. If knowledge gaps surface → Phase 4.

---

## Phase 4 — Anki cards (yanki format)

When a knowledge gap is confirmed:

- Write one card per concept under `anki/<topic>/<slug>.md`.
- **yanki rules** (see `anki/README.md` for full reference):
  - Folder = deck name (e.g., `anki/arrays-hashing/` → deck `arrays-hashing`).
  - One file = one note.
  - Front and back separated by a line containing only `---`.
  - A line `---` followed by another `---` makes the card reversible.
  - Pure Markdown; no Anki-specific markup.
- Keep cards atomic (one idea per card). Link back to the problem in the back face.

Example card file `anki/arrays-hashing/complement-lookup.md`:
```markdown
Two-sum complement lookup — what data structure and why?

---

Hash map: store each value's index as you scan.
For each element x, check if `target - x` is already in the map.
O(n) time, O(n) space.
→ `problems/0001-two-sum/`
```
