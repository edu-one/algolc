<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0242 — Valid Anagram

**URL:** https://leetcode.com/problems/valid-anagram/
**Difficulty:** Easy
**Topics:** Hash Table, String, Sorting

## Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`,
and `false` otherwise.

An **anagram** is a word or phrase formed by rearranging the letters of a
different word or phrase, using all the original letters exactly once.

**Follow-up:** What if the inputs contain Unicode characters? How would you
adapt your solution to such a case?

## Constraints

- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters.

## Examples

### Example 1

- Input: `s = "anagram"`, `t = "nagaram"`
- Output: `true`

### Example 2

- Input: `s = "rat"`, `t = "car"`
- Output: `false`
- Explanation: `t` has a `c` that never appears in `s`.

## Complexity Targets

- Time: O(n)
- Space: O(1) — the alphabet is fixed at 26 lowercase letters
