<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0003 — Longest Substring Without Repeating Characters

**URL:** https://leetcode.com/problems/longest-substring-without-repeating-characters/
**Difficulty:** Medium
**Topics:** Hash Table, String, Sliding Window

## Problem Statement

Given a string `s`, find the length of the longest substring without duplicate characters.

## Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols and spaces.

## Examples

**Example 1:**

```
Input: s = "abcabcbb"
Output: 3
```

The answer is `"abc"`, with the length of 3. Note that `"bca"` and `"cab"` are also correct
answers.

**Example 2:**

```
Input: s = "bbbbb"
Output: 1
```

The answer is `"b"`, with the length of 1.

**Example 3:**

```
Input: s = "pwwkew"
Output: 3
```

The answer is `"wke"`, with the length of 3. Notice that the answer must be a substring,
`"pwke"` is a subsequence and not a substring.

## Complexity Targets

- Time: O(n)
- Space: O(min(n, charset size))
