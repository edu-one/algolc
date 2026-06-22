# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

"""Scaffold a new LeetCode problem folder under problems/<id>-<slug>/."""

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


def main(argv):
    if len(argv) != 3:
        print("usage: python scripts/new_problem.py <id> <slug>", file=sys.stderr)
        print("example: python scripts/new_problem.py 0042 trapping-rain-water",
              file=sys.stderr)
        return 2

    pid, slug = argv[1], argv[2]
    if not re.fullmatch(r"[0-9]{4}", pid):
        print("id must be 4 digits, e.g. 0042", file=sys.stderr)
        return 2
    if not re.fullmatch(r"[a-z0-9]+(-[a-z0-9]+)*", slug):
        print("slug must be kebab-case, e.g. trapping-rain-water", file=sys.stderr)
        return 2

    root = Path(__file__).resolve().parent.parent
    folder = root / "problems" / f"{pid}-{slug}"
    if folder.exists():
        print(f"{folder} already exists", file=sys.stderr)
        return 1
    folder.mkdir(parents=True)

    guard = "__DV_LC_{}_{}_HPP__".format(pid, slug.upper().replace("-", "_"))
    suite = "".join(part.capitalize() for part in slug.split("-"))

    (folder / "solution.hpp").write_text(
        SOLUTION_TMPL.format(guard=guard, id=pid, slug=slug), encoding="utf-8")
    (folder / "test.cpp").write_text(
        TEST_TMPL.format(suite=suite, id=pid, slug=slug), encoding="utf-8")

    print(f"created {folder}")
    print("next: cmake --preset conan-default  # pick up the new folder")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv))
