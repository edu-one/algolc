# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

import pytest
from solution import Solution


@pytest.mark.skip(reason="implement solution first")
def test_placeholder():
    s = Solution()
    assert s.longestCommonPrefix(["flower", "flow", "flight"]) == "fl"
