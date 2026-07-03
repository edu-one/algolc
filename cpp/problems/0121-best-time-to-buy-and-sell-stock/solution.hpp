/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0121_BEST_TIME_TO_BUY_AND_SELL_STOCK_HPP
#define DV_LC_0121_BEST_TIME_TO_BUY_AND_SELL_STOCK_HPP

#include <algorithm>
#include <limits>
#include <vector>

namespace dv::lc {

class Solution {
public:
    int maxProfit(const std::vector<int> &prices) {
        int profit = 0;
        int min = std::numeric_limits<int>::max();
        for (const auto p : prices) {
            if (min > p) {
                min = p;
                continue;
            }
            const auto diff = p - min;
            profit = std::max(profit, diff);
        }
        return profit;
    }
};

} // namespace dv::lc

#endif // DV_LC_0121_BEST_TIME_TO_BUY_AND_SELL_STOCK_HPP
