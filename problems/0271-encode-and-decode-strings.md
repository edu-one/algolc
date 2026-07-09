<!-- Copyright (C) Denys Valchuk - All Rights Reserved
     ZHZhbGNodWtAZ21haWwuY29tCg== -->

# 0271 — Encode And Decode Strings

**URL:** https://leetcode.com/problems/encode-and-decode-strings/ (Premium)
**Difficulty:** Medium
**Topics:** Array, String, Design

## Problem Statement

Design an algorithm to encode a list of strings to a single string. The encoded string
is then sent over the network and decoded back to the original list of strings.

Implement `encode` and `decode`:

- `encode(strs)` — encodes a list of strings into a single string.
- `decode(s)` — decodes a single string back into the original list of strings.

Machine 1 (encode) and Machine 2 (decode) do not share any state, so the encoding must be
self-describing: `decode` must be able to recover the exact original list purely from the
encoded string, including strings that are empty or that contain arbitrary characters
(delimiters, digits, unicode, etc.) that could otherwise be mistaken for encoding metadata.

## Constraints

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` may contain any of the 256 valid ASCII characters.

## Examples

**Example 1**
Input: `strs = ["Hello","World"]`
Output: `["Hello","World"]`
Explanation: `encode` turns the list into one string; `decode` recovers the original list
from it.

**Example 2**
Input: `strs = [""]`
Output: `[""]`
Explanation: A single empty string must round-trip correctly.

**Example 3**
Input: `strs = ["4","two#three","","abc:def"]`
Output: `["4","two#three","","abc:def"]`
Explanation: Strings containing digits and common delimiter characters (`#`, `:`) must not
break the encoding.

## Complexity Targets

- Time: O(n) for both `encode` and `decode`, where n is the total number of characters
  across all strings.
- Space: O(n) for the encoded string / decoded output.
