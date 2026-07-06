# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

"""Scaffold a new LeetCode problem; shared statement at problems/<id>-<slug>.md."""

import argparse
import re
import sys
from pathlib import Path

HEADER = """/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */
"""

SOLUTION_TMPL = HEADER + """
#ifndef {guard}
#define {guard}

namespace dv::lc {{

    class Solution {{
    public:
        // TODO: solve {id} - {slug}
    }};

}} // namespace dv::lc

#endif // {guard}
"""

TEST_TMPL = HEADER + """
#include "solution.hpp"

#include <gtest/gtest.h>

TEST({suite}, Placeholder) {{
    dv::lc::Solution s;
    (void)s;
    FAIL() << "write a real test for {id} - {slug}";
}}
"""

README_TMPL = """\
<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# {id} — {title}

**URL:** https://leetcode.com/problems/{slug}/
**Difficulty:**
**Topics:**

## Problem Statement

<!-- paste or expand here -->

## Constraints

<!-- list constraints -->

## Examples

<!-- input → output → explanation -->

## Complexity Targets

- Time: O(?)
- Space: O(?)
"""

CARGO_TMPL = """\
# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

[package]
name = "p{id}-{slug}"
version = "0.1.0"
edition = "2021"

[lib]
name = "p{id}_{slug_underscored}"
"""

RUST_LIB_TMPL = HEADER + """
pub struct Solution;

impl Solution {{
    // TODO: solve {id} - {slug}
}}

#[cfg(test)]
mod tests {{
    use super::*;

    #[test]
    #[ignore = "implement solution first"]
    fn placeholder() {{
        let _s = Solution;
    }}
}}
"""

PYTHON_SOLUTION_TMPL = """\
# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==


class Solution:
    # TODO: solve {id} - {slug}
    pass
"""

PYTHON_TEST_TMPL = """\
# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

import pytest
from solution import Solution


@pytest.mark.skip(reason="implement solution first")
def test_placeholder():
    s = Solution()
    assert s is not None, "write a real test for {id} - {slug}"
"""

PYTHON_CONFTEST_TMPL = """\
# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

import sys
from pathlib import Path

_problem_dir = str(Path(__file__).parent)

# Ensure this problem's directory is first so local imports resolve correctly
if _problem_dir in sys.path:
    sys.path.remove(_problem_dir)
sys.path.insert(0, _problem_dir)

# Invalidate any cached 'solution' module so Python loads from this directory
if "solution" in sys.modules:
    del sys.modules["solution"]
"""


def write_file(path: Path, root: Path, content: str) -> bool:
    """Write content to path using LF line endings.

    Returns True if created, False if skipped (already exists).
    """
    rel = path.relative_to(root).as_posix()
    if path.exists():
        print(f"skipped (exists): {rel}")
        return False
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(content.encode("utf-8"))
    print(f"created {rel}")
    return True


def main():
    parser = argparse.ArgumentParser(
        description="Scaffold a new LeetCode problem folder.",
        usage="%(prog)s <id> [slug] [--rust] [--python] [--no-cpp]",
    )
    parser.add_argument("id", help="4-digit problem id, e.g. 0042")
    parser.add_argument(
        "slug",
        nargs="?",
        help="kebab-case slug, e.g. trapping-rain-water (optional if problem dir exists)",
    )
    parser.add_argument("--rust", action="store_true", help="scaffold Rust problem")
    parser.add_argument("--python", action="store_true", help="scaffold Python problem")
    parser.add_argument(
        "--no-cpp", dest="no_cpp", action="store_true", help="skip C++ scaffold"
    )
    args = parser.parse_args()

    pid = args.id
    if not re.fullmatch(r"[0-9]{4}", pid):
        print("error: id must be 4 digits, e.g. 0042", file=sys.stderr)
        return 2

    do_cpp = not args.no_cpp
    do_rust = args.rust
    do_python = args.python

    if not do_cpp and not do_rust and not do_python:
        print(
            "error: at least one language required"
            " (remove --no-cpp or add --rust / --python)",
            file=sys.stderr,
        )
        return 2

    root = Path(__file__).resolve().parent.parent

    # Resolve slug — required for new problems, optional for existing ones
    slug = args.slug
    if slug is None:
        matches = sorted((root / "problems").glob(f"{pid}-*.md"))
        if len(matches) == 0:
            print(
                f"error: no problems/{pid}-*.md file found; provide slug as second argument",
                file=sys.stderr,
            )
            return 2
        elif len(matches) > 1:
            names = ", ".join(m.name for m in matches)
            print(
                f"error: ambiguous — multiple files match {pid}-*.md: {names}",
                file=sys.stderr,
            )
            return 2
        slug = matches[0].stem[len(pid) + 1:]
    else:
        if not re.fullmatch(r"[a-z0-9]+(-[a-z0-9]+)*", slug):
            print(
                "error: slug must be kebab-case, e.g. trapping-rain-water",
                file=sys.stderr,
            )
            return 2

    # Derive naming variants
    guard = "DV_LC_{}_{}_HPP".format(pid, slug.upper().replace("-", "_"))
    suite = "".join(part.capitalize() for part in slug.split("-"))
    title = " ".join(part.capitalize() for part in slug.split("-"))
    slug_underscored = slug.replace("-", "_")

    # README (shared, always created alongside the first language)
    write_file(
        root / "problems" / f"{pid}-{slug}.md",
        root,
        README_TMPL.format(id=pid, slug=slug, title=title),
    )

    # C++ scaffold
    if do_cpp:
        cpp_dir = root / "cpp" / "problems" / f"{pid}-{slug}"
        write_file(
            cpp_dir / "solution.hpp",
            root,
            SOLUTION_TMPL.format(guard=guard, id=pid, slug=slug),
        )
        write_file(
            cpp_dir / "test.cpp",
            root,
            TEST_TMPL.format(suite=suite, id=pid, slug=slug),
        )

    # Rust scaffold
    if do_rust:
        rust_dir = root / "rust" / "problems" / f"{pid}-{slug}"
        write_file(
            rust_dir / "Cargo.toml",
            root,
            CARGO_TMPL.format(id=pid, slug=slug, slug_underscored=slug_underscored),
        )
        write_file(
            rust_dir / "src" / "lib.rs",
            root,
            RUST_LIB_TMPL.format(id=pid, slug=slug),
        )

    # Python scaffold
    if do_python:
        py_dir = root / "python" / "problems" / f"{pid}-{slug}"
        write_file(
            py_dir / "solution.py",
            root,
            PYTHON_SOLUTION_TMPL.format(id=pid, slug=slug),
        )
        write_file(
            py_dir / "test_solution.py",
            root,
            PYTHON_TEST_TMPL.format(id=pid, slug=slug),
        )
        write_file(py_dir / "conftest.py", root, PYTHON_CONFTEST_TMPL)

    # Next steps
    print()
    print("next steps:")
    if do_cpp:
        print("  C++:    cd cpp && cmake --preset conan-default")
    if do_rust:
        print(f"  Rust:   cd rust && cargo test -p p{pid}-{slug}")
    if do_python:
        print(f"  Python: cd python && pytest problems/{pid}-{slug}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
