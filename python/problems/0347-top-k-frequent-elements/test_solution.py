# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from solution import Solution


def top_k_frequent(nums, k):
    s = Solution()
    return sorted(s.topKFrequent(nums, k))


def test_example1_mixed_frequencies():
    assert top_k_frequent([1, 1, 1, 2, 2, 3], 2) == [1, 2]


def test_example2_single_element():
    assert top_k_frequent([1], 1) == [1]


def test_example3_tied_frequencies():
    assert top_k_frequent([1, 2, 1, 2, 1, 2, 3, 1, 3, 2], 2) == [1, 2]


def test_k_equals_unique_count_returns_all():
    assert top_k_frequent([1, 2, 3], 3) == [1, 2, 3]


def test_negative_numbers():
    assert top_k_frequent([-1, -1, -1, 5, 5, 2], 2) == [-1, 5]


def test_all_same_element():
    assert top_k_frequent([7, 7, 7, 7], 1) == [7]


def test_k_equals_one_picks_most_frequent():
    assert top_k_frequent([1, 2, 4, 4, 4, 3, 3], 1) == [4]
