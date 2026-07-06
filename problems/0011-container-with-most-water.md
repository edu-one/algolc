<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0011 — Container With Most Water

**URL:** https://leetcode.com/problems/container-with-most-water/
**Difficulty:** Medium
**Topics:** Array, Two Pointers, Greedy

## Problem Statement

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn
such that the two endpoints of the `i`th line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container
contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

## Constraints

- `n == height.length`
- `2 <= n <= 10^5`
- `0 <= height[i] <= 10^4`

## Examples

**Example 1:**

```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
```

The lines at index 1 (height 8) and index 8 (height 7) form the best container:
width `8 - 1 = 7`, height `min(8, 7) = 7`, area `7 * 7 = 49`.

**Example 2:**

```
Input: height = [1,1]
Output: 1
```

## Complexity Targets

- Time: O(n)
- Space: O(1)
