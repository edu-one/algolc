/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0347_TOP_K_FREQUENT_ELEMENTS_HPP
#define DV_LC_0347_TOP_K_FREQUENT_ELEMENTS_HPP

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace dv::lc {

using Appearance = std::unordered_map<int, size_t>;

class Solution {
public:
    std::vector<int> topKFrequent(const std::vector<int> &nums, int k) {
        Appearance app;
        app.reserve(nums.size());
        std::vector<Appearance::iterator> resultAll;
        std::vector<int> result;
        result.reserve(k);
        for (int n : nums) {
            auto fit = app.find(n);
            if (fit == app.end()) {
                auto inserted = app.insert(std::make_pair(n, 1));
                resultAll.push_back(inserted.first);
            } else
                ++fit->second;
        }

        std::partial_sort(resultAll.begin(), resultAll.begin() + k, resultAll.end(),
                          [](const auto &lhs, const auto &rhs) { return lhs->second > rhs->second; });

        for (int i = 0; i < k; ++i) {
            const int v = resultAll[i]->first;
            result.push_back(v);
        }
        return result;
    }
};

} // namespace dv::lc

#endif // DV_LC_0347_TOP_K_FREQUENT_ELEMENTS_HPP
