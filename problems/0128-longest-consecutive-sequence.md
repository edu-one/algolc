<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0128 — Longest Consecutive Sequence

**URL:** https://leetcode.com/problems/longest-consecutive-sequence/
**Difficulty:** Medium
**Topics:** Array, Hash Table, Union Find

## Problem Statement

Given an unsorted array of integers `nums`, return the length of the longest consecutive
elements sequence.

You must write an algorithm that runs in `O(n)` time.

## Constraints

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Examples

- Input: `nums = [100,4,200,1,3,2]` → Output: `4`
  (The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.)
- Input: `nums = [0,3,7,2,5,8,4,6,0,1]` → Output: `9`
- Input: `nums = [1,0,1,2]` → Output: `3`
  (Duplicates don't extend a sequence; the longest run is `[0, 1, 2]`.)

## Complexity Targets

- Time: O(n) — hash-set membership check; only start counting a run from numbers that are
  the start of a sequence (i.e. `n - 1` not present), so each number is visited at most twice.
- Space: O(n)
