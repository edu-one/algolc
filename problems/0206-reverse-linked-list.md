<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0206 — Reverse Linked List

**URL:** https://leetcode.com/problems/reverse-linked-list/
**Difficulty:** Easy
**Topics:** Linked List, Recursion

## Problem Statement

Given the head of a singly linked list, reverse the list, and return the reversed list.

**Follow up:** A linked list can be reversed either iteratively or recursively. Could you
implement both?

## Constraints

- The number of nodes in the list is in the range `[0, 5000]`.
- `-5000 <= Node.val <= 5000`

## Examples

**Example 1:**
- Input: `head = [1,2,3,4,5]`
- Output: `[5,4,3,2,1]`

**Example 2:**
- Input: `head = [1,2]`
- Output: `[2,1]`

**Example 3:**
- Input: `head = []`
- Output: `[]`

## Complexity Targets

- Time: O(n)
- Space: O(1) iterative / O(n) recursive (call stack)
