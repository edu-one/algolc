# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        result = strs[0]
        for s in strs[1:]:
            idx = 0
            while idx < len(s) and idx < len(result) and result[idx] == s[idx]:
                idx += 1
            result = result[:idx]
            if not result:
                break
        return result
