/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0020_VALID_PARENTHESES_HPP
#define DV_LC_0020_VALID_PARENTHESES_HPP

#include <stack>
#include <string>
#include <unordered_map>

namespace dv::lc {

class Solution {
    const std::unordered_map<char, char> pairs = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

public:
    bool isValid(std::string s) {
        std::stack<char> pack;
        for (auto c : s) {
            if (c == '(' || c == '[' || c == '{') {
                pack.push(c);
                continue;
            } else {
                if (pack.empty())
                    return false;
                const auto close = pairs.find(c)->second; // should always return valid iterator
                const auto last = pack.top();
                if (last != close)
                    return false;
                pack.pop();
            }
        }
        return pack.empty();
    }
};

} // namespace dv::lc

#endif // DV_LC_0020_VALID_PARENTHESES_HPP
