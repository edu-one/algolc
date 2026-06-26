# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

import pytest
from solution import Solution


@pytest.mark.skip(reason="implement solution first")
def test_placeholder():
    s = Solution()
    assert s.twoSum([2, 7, 11, 15], 9) == [0, 1]
