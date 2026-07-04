/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0011_CONTAINER_WITH_MOST_WATER_HPP
#define DV_LC_0011_CONTAINER_WITH_MOST_WATER_HPP

#include <algorithm>
#include <vector>

namespace dv::lc {

class Solution {
public:
    int maxArea(const std::vector<int> &height) {
        int max_area = 0;
        for (size_t i = 0, j = height.size() - 1; i < j;) {
            const auto l = height[i];
            const auto r = height[j];
            if (!l) {
                ++i;
                continue;
            }
            if (!r) {
                --j;
                continue;
            }
            const auto h = std::min(r, l);
            const int w = static_cast<int>(j - i);
            const auto area = h * w;
            max_area = std::max(area, max_area);
            if (l < r)
                ++i;
            else
                --j;
        }
        return max_area;
    }
};

} // namespace dv::lc

#endif // DV_LC_0011_CONTAINER_WITH_MOST_WATER_HPP
