//
// Created by Emanuel on 12.09.2022.
//

#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (!nums.size()) {
            return -1;
        }

        int largestSum = nums[0], currentSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currentSum = currentSum < 0 ? nums[i] : currentSum + nums[i];
            largestSum = currentSum > largestSum ? currentSum : largestSum;
        }

        return largestSum;
    }
};
