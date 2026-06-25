<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0094 — Binary Tree Inorder Traversal

**URL:** https://leetcode.com/problems/binary-tree-inorder-traversal/
**Difficulty:** Easy
**Topics:** Tree, Depth-First Search, Binary Tree, Stack

## Problem Statement

Given the `root` of a binary tree, return the inorder traversal of its nodes' values.

## Constraints

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## Examples

**Example 1:**
```
Input:  root = [1,null,2,3]
Output: [1,3,2]
```
Tree: `1 -> (null, 2(3, null))`
Inorder visits: 1, then left-of-2 (=3), then 2.

**Example 2:**
```
Input:  root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [4,2,6,5,7,1,3,9,8]
```

**Example 3:**
```
Input:  root = []
Output: []
```

**Example 4:**
```
Input:  root = [1]
Output: [1]
```

## Complexity Targets

- Time: O(n) — every node visited once
- Space: O(h) — call stack / explicit stack depth proportional to tree height h; O(n) worst case (skewed tree)

## Follow-up

Recursive solution is trivial. Can you do it **iteratively** using an explicit stack?
