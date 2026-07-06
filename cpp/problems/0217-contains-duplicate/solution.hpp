/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0217_CONTAINS_DUPLICATE_HPP
#define DV_LC_0217_CONTAINS_DUPLICATE_HPP

#include <unordered_set>
#include <vector>

namespace dv::lc {

class Solution {
public:
    bool containsDuplicate(std::vector<int> &nums) {
        std::unordered_set<int> visited;
        for (const auto &n : nums) {
            if (!visited.insert(n).second)
                return true;
        }
        return false;
    }
};

} // namespace dv::lc

#endif // DV_LC_0217_CONTAINS_DUPLICATE_HPP
