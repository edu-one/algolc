/* Copyright (C) Denys Valchuk - All Rights Reserved
 * ZHZhbGNodWtAZ21haWwuY29tCg==
 */

#ifndef DV_LC_0049_GROUP_ANAGRAMS_HPP
#define DV_LC_0049_GROUP_ANAGRAMS_HPP

#include <array>
#include <string>
#include <unordered_map>
#include <vector>

namespace dv::lc {

using Strings = std::vector<std::string>;
using Presence = std::array<int, 26>;

struct PresenceHash {
    std::size_t operator()(const Presence &p) const noexcept {
        std::size_t h = std::hash<int>{}(p[0]);
        for (size_t i = 1; i < p.size(); ++i) {
            const auto hi = std::hash<int>{}(p[i]);
            h = h ^ (hi << 1);
        }
        return h;
    }
};

using PresenceGroups = std::unordered_map<Presence, size_t, PresenceHash>;

class Solution {

    Presence getPresenceKey(const std::string &s) const {
        Presence result{};
        for (const auto c : s) {
            const int cp = static_cast<int>(c) - static_cast<int>('a');
            ++result[cp];
        }
        return result;
    }

public:
    std::vector<Strings> groupAnagrams(Strings &strs) {
        std::vector<Strings> result;
        PresenceGroups presenceGroups;
        for (const auto &is : strs) {
            bool found = false;
            auto isPresenceKey = getPresenceKey(is);
            const auto fit = presenceGroups.find(isPresenceKey);
            if (fit == presenceGroups.end()) {
                result.push_back(Strings{is});
                presenceGroups.emplace(isPresenceKey, result.size() - 1);
            } else {
                result[fit->second].push_back(is);
            }
        }
        return result;
    }
};

} // namespace dv::lc

#endif // DV_LC_0049_GROUP_ANAGRAMS_HPP
