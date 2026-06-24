# Claude instructions for `algolc`

## Project conventions

**Stack:** C++20 · Conan 2 · CMake ≥ 3.23 presets · GoogleTest 1.14 (`gtest::gtest`) · CTest.

**Layout:** `problems/<id>-<slug>/` — each problem is a self-contained folder with exactly two source files: `solution.hpp` (header-only) and `test.cpp`. No build-system edits are needed when a new folder appears; CMake auto-discovers it via `file(GLOB ...)`.

**Namespace:** `dv::lc` — every solution lives inside `namespace dv::lc { ... }`.

**Header guards:** `DV_LC_<ID>_<SLUG>_HPP` — uppercase, no leading underscores.  
Example: `0042-trapping-rain-water` → `DV_LC_0042_TRAPPING_RAIN_WATER_HPP`.

**Copyright header:** every C++/CMake/Python file starts with the canonical block.  
The authoritative text is in `scripts/new_problem.py` (`HEADER`). Copy it verbatim — do not retype or paraphrase:
```
/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */
```

**Formatting:** `.clang-format` governs C++; `.cmake-format` governs CMake. Run `clang-format` on every C++ file you touch.

**Line endings:** LF only (`\n`). Never write CRLF (`\r\n`). This applies to every file you create or edit — C++, CMake, Python, Markdown, etc. When using the Write tool, ensure the content uses LF line endings.

**Shared helpers:** `common/include/dv/lc.hpp`, included as `<dv/lc.hpp>`. Currently provides `ListNode`. Prefer helpers from there over reinventing them in test files.

**Test style:** suite name = PascalCase slug (`MergeTwoLists`), helper functions in an anonymous namespace. See `problems/0021-merge-two-sorted-lists/test.cpp` for the canonical example.

---

## Build & test commands

```bash
# Install dependencies (once, or after conanfile.py changes)
conan install . --build=missing

# Configure CMake (re-run whenever a new problem folder appears)
cmake --preset conan-default

# Build + test a single problem
cmake --build --preset conan-release --target p_<id>_<slug>
ctest --preset conan-release -R <id>

# Build + test everything
cmake --build --preset conan-release
ctest --preset conan-release
```

Target name convention: `p_0042_trapping_rain_water` (underscores, not hyphens).

---

## Phase 1 — Problem setup

When the user says "set up problem N" or equivalent:

1. **Acquire the problem statement.**  
   - If given a LeetCode URL, attempt `WebFetch`. If the fetch is thin or incomplete, ask the user to paste the statement.  
   - If text is pasted directly, use it as-is.

2. **Scaffold the folder:**
   ```bash
   python scripts/new_problem.py <id> <slug>
   cmake --preset conan-default
   ```

3. **Write `problems/<id>-<slug>/README.md`** — the browsable GitHub reference for this problem:
   - Title + LeetCode URL
   - Difficulty (`Easy` / `Medium` / `Hard`)
   - Topics/tags (e.g., `Array`, `Hash Table`, `Two Pointers`)
   - Full problem statement
   - Constraints
   - Worked examples (input → output → explanation)
   - Target time and space complexity (derive from constraints; confirm with user if uncertain)

4. **Replace the placeholder in `test.cpp`** with real GoogleTest cases:
   - All examples from the problem statement.
   - Edge cases derived from the constraints: empty inputs, min/max values, duplicates, single elements, all-equal arrays, etc.
   - Follow the test style in `0021-merge-two-sorted-lists/test.cpp` (anonymous-namespace helpers, PascalCase suite name, `EXPECT_EQ` etc.).
   - For large or reusable datasets, put them in a `dataset.hpp` in the problem folder and `#include` from the test; keep small cases inline.

5. **Do not fill in `solution.hpp`.** Leave the stub (`// TODO: solve ...`) for the user to solve.

6. **Benchmarks** — opt-in only. Google Benchmark is not a current Conan dependency; adding it is a separate change. Flag it and do it only if explicitly asked.

---

## Phase 2 — Interview coach (graduated hints)

When the user is working on a problem and asks for help:

- Default to the smallest useful nudge: a clarifying question or a single observation.
- Escalate only when the user asks for more:
  1. **Nudge** — point at the key insight without stating it ("what happens at the boundary?")
  2. **Approach** — name the technique/pattern at high level ("two-pointer scan")
  3. **Pseudocode + complexity** — outline the algorithm; state time/space complexity
  4. **Full solution** — only when the user explicitly says they want it

Stay in the user's chosen language and idioms; reference repo conventions (namespace, guards) when relevant.

---

## Phase 3 — Solution review

When the user says they're done (or "review my solution"):

1. Read `solution.hpp`.
2. **Correctness** — trace through the provided examples and edge cases mentally; flag any case that would fail.
3. **Complexity** — state time and space complexity; compare to the targets in `README.md`.
4. **Conventions** — check namespace, header guard, copyright header, formatting.
5. **Build + test** — run:
   ```bash
   cmake --build --preset conan-release --target p_<id>_<slug>
   ctest --preset conan-release -R <id>
   ```
   Report results honestly; do not claim green if there are failures.
6. **Follow-ups** — ask 2–3 interviewer-style questions: alternative approaches, scaling to larger inputs, trade-offs.
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
