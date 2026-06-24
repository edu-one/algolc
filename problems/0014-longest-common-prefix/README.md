<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0014 — Longest Common Prefix

**URL:** https://leetcode.com/problems/longest-common-prefix/  
**Difficulty:** Easy  
**Topics:** String, Trie

## Problem Statement

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

## Constraints

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lowercase English letters if it is non-empty.

## Examples

| Input | Output | Explanation |
|-------|--------|-------------|
| `["flower","flow","flight"]` | `"fl"` | Common prefix is "fl" |
| `["dog","racecar","car"]` | `""` | No common prefix |

## Complexity Targets

- Time: O(S) where S is the total number of characters across all strings
- Space: O(1) extra (result is at most the length of the shortest string)
