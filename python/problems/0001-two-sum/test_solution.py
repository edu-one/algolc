# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from solution import Solution


def test_example1():
    s = Solution()
    assert s.twoSum([2, 7, 11, 15], 9) == [0, 1]


def test_example2():
    s = Solution()
    assert s.twoSum([3, 2, 4], 6) == [1, 2]


def test_same_value_twice():
    s = Solution()
    assert s.twoSum([3, 3], 6) == [0, 1]
