<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0019 — Remove Nth Node From End of List

**URL:** https://leetcode.com/problems/remove-nth-node-from-end-of-list/
**Difficulty:** Medium
**Topics:** Linked List, Two Pointers

## Problem Statement

Given the `head` of a linked list, remove the `n`-th node from the end of the list and
return its head.

## Constraints

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

## Examples

**Example 1:**

```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

The second node from the end (`4`) is removed.

**Example 2:**

```
Input: head = [1], n = 1
Output: []
```

The only node is removed; the list becomes empty.

**Example 3:**

```
Input: head = [1,2], n = 1
Output: [1]
```

The last node (`2`) is removed.

## Complexity Targets

- Time: O(n)
- Space: O(n) recursion or O(1) two-pointer — the problem itself sets no space requirement.

Follow-up: could you do this in one pass?
