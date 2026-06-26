# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from solution import Solution


def test_example1_flower_flow_flight():
    s = Solution()
    assert s.longestCommonPrefix(["flower", "flow", "flight"]) == "fl"


def test_example2_no_common_prefix():
    s = Solution()
    assert s.longestCommonPrefix(["dog", "racecar", "car"]) == ""


def test_single_string():
    s = Solution()
    assert s.longestCommonPrefix(["alone"]) == "alone"


def test_all_identical():
    s = Solution()
    assert s.longestCommonPrefix(["abc", "abc", "abc"]) == "abc"


def test_empty_string_in_array():
    s = Solution()
    assert s.longestCommonPrefix(["abc", "", "ab"]) == ""


def test_all_empty():
    s = Solution()
    assert s.longestCommonPrefix(["", "", ""]) == ""


def test_single_char_prefix():
    s = Solution()
    assert s.longestCommonPrefix(["abc", "axy", "az"]) == "a"


def test_prefix_equals_shortest_string():
    s = Solution()
    assert s.longestCommonPrefix(["ab", "abc", "abcd"]) == "ab"


def test_long_strings_one_truncation():
    base = "a" * 200
    diff = "a" + "b" * 199
    s = Solution()
    assert s.longestCommonPrefix([base, diff]) == "a"
