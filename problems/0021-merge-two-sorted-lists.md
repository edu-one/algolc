<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0021 — Merge Two Sorted Lists

**URL:** https://leetcode.com/problems/merge-two-sorted-lists/
**Difficulty:** Easy
**Topics:** Linked List, Recursion

## Problem Statement

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

## Constraints

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in non-decreasing order.

## Examples

**Example 1:**

![Merge Two Sorted Lists](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

- Input: `list1 = [1,2,4]`, `list2 = [1,3,4]`
- Output: `[1,1,2,3,4,4]`

**Example 2:**
- Input: `list1 = []`, `list2 = []`
- Output: `[]`

**Example 3:**
- Input: `list1 = []`, `list2 = [0]`
- Output: `[0]`

## Complexity Targets

- Time: O(n + m)
- Space: O(1)
