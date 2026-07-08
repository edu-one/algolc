<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0347 — Top K Frequent Elements

**URL:** https://leetcode.com/problems/top-k-frequent-elements/
**Difficulty:** Medium
**Topics:** Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect

## Problem Statement

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements.
You may return the answer in any order.

## Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `k` is in the range `[1, the number of unique elements in the array]`.
- It is guaranteed that the answer is unique.
- Follow-up: your algorithm's time complexity must be better than `O(n log n)`, where `n` is the array's size.

## Examples

- Input: `nums = [1,1,1,2,2,3]`, `k = 2` → Output: `[1,2]`
  (1 appears 3 times, 2 appears 2 times, 3 appears once; the two most frequent are 1 and 2.)
- Input: `nums = [1]`, `k = 1` → Output: `[1]`
- Input: `nums = [1,2,1,2,1,2,3,1,3,2]`, `k = 2` → Output: `[1,2]`
  (1 appears 4 times, 2 appears 4 times, 3 appears 2 times; the two most frequent are 1 and 2.)

## Complexity Targets

- Time: O(n) — bucket sort on frequency (index = count, up to n buckets), satisfying the
  better-than-O(n log n) follow-up. A heap-based O(n log k) solution is an acceptable fallback.
- Space: O(n)
