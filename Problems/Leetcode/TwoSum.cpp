//
// Created by Emanuel on 14.02.2022.
//

#include <vector>
#include <unordered_map>

class Solution {
public:
    // Time Complexity: O(n) on average
    // Extra-Space Complexity: O(n)
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> complements;
        std::vector<int> elems;

        for (int i = 0; i < nums.size(); ++i) {
            auto mapping = complements.find(target - nums[i]);
            if (mapping != complements.end())
                return {mapping->second, i};

            complements.insert({nums[i], i});
        }

        return {};
    }
};
