<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0238 — Product Of Array Except Self

**URL:** https://leetcode.com/problems/product-of-array-except-self/
**Difficulty:** Medium
**Topics:** Array, Prefix Sum

## Problem Statement

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the
product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

## Constraints

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.
- Follow-up: Could you solve it in `O(n)` time complexity and `O(1)` extra space complexity
  (the output array does not count as extra space for space complexity analysis)?

## Examples

- Input: `nums = [1,2,3,4]` → Output: `[24,12,8,6]`
- Input: `nums = [-1,1,0,-3,3]` → Output: `[0,0,9,0,0]`

## Complexity Targets

- Time: O(n) — two passes (prefix products, then suffix products), no division.
- Space: O(1) extra — accumulate the suffix product in a scalar while writing into the
  (already-allocated) output array; output array itself doesn't count.
