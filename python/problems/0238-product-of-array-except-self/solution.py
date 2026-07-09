# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1] * len(nums)  # act as a suffix
        prefix = [1] * len(nums)
        for i in range(1, len(nums)):
            j = len(nums) - i - 1
            prefix[i] = prefix[i - 1] * nums[i - 1]
            result[j] = result[j + 1] * nums[j + 1]
        for i in range(len(nums)):
            result[i] = result[i] * prefix[i]
        return result
