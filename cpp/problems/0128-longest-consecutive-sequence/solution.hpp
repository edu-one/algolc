/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0128_LONGEST_CONSECUTIVE_SEQUENCE_HPP
#define DV_LC_0128_LONGEST_CONSECUTIVE_SEQUENCE_HPP

#include <algorithm>
#include <unordered_set>
#include <vector>

namespace dv::lc {

class Solution {
public:
    int longestConsecutive(const std::vector<int> &nums) {
        int maxRange = 0;
        std::unordered_set<int> presence(nums.begin(), nums.end());
        for (int n : nums) {
            if (presence.contains(n + 1))
                continue;
            int range = 0;
            do {
                ++range;
                --n;
            } while (presence.contains(n));
            maxRange = std::max(range, maxRange);
        }
        return maxRange;
    }
};

} // namespace dv::lc

#endif // DV_LC_0128_LONGEST_CONSECUTIVE_SEQUENCE_HPP
