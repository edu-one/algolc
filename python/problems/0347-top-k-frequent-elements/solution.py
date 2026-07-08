# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from typing import List


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        appearance = {}
        for n in nums:
            appearance[n] = appearance.get(n, 0) + 1
        buckets = [[] for _ in range(len(nums))]
        for n, freq in appearance.items():
            buckets[freq - 1].append(n)
        i = len(nums) - 1
        result = []
        while i >= 0:
            b = buckets[i]
            if not b:
                i -= 1
                continue
            for n in b:
                result.append(n)
                if len(result) == k:
                    return result
            i -= 1
        return result
