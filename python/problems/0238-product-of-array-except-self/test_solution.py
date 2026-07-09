# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from solution import Solution


def product_except_self(nums):
    s = Solution()
    return s.productExceptSelf(nums)


def test_example1():
    assert product_except_self([1, 2, 3, 4]) == [24, 12, 8, 6]


def test_example2():
    assert product_except_self([-1, 1, 0, -3, 3]) == [0, 0, 9, 0, 0]


def test_single_zero():
    assert product_except_self([0, 1, 2, 3]) == [6, 0, 0, 0]


def test_multiple_zeros():
    assert product_except_self([0, 2, 0, 4]) == [0, 0, 0, 0]


def test_two_elements():
    assert product_except_self([7, 5]) == [5, 7]


def test_negative_numbers():
    assert product_except_self([-2, 3, -4, 6, -3]) == [216, -144, 108, -72, 144]
