<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0049 — Group Anagrams

**URL:** https://leetcode.com/problems/group-anagrams/
**Difficulty:** Medium
**Topics:** Array, Hash Table, String, Sorting

## Problem Statement

Given an array of strings `strs`, group the **anagrams** together. You can return
the answer in **any order**.

An anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, using all the original letters exactly once.

## Constraints

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.

## Examples

### Example 1

- Input: `strs = ["eat","tea","tan","ate","nat","bat"]`
- Output: `[["bat"],["nat","tan"],["ate","eat","tea"]]`
- Explanation: `"tan"`/`"nat"` and `"eat"`/`"tea"`/`"ate"` are anagram groups;
  `"bat"` has no anagram in the input.

### Example 2

- Input: `strs = [""]`
- Output: `[[""]]`

### Example 3

- Input: `strs = ["a"]`
- Output: `[["a"]]`

## Complexity Targets

- Time: O(n·k) — n strings of length ≤ k, using a character-count key
  (O(n·k log k) with a sorted-string key is also acceptable)
- Space: O(n·k)
