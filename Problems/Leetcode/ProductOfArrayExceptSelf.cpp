//
// Created by Emanuel on 16.10.2021.
//

#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> result (nums.size(), 0);

    for (int i = 1; i < nums.size(); ++i)
        if (i == 1) result[i] = nums[i - 1];
        else result[i] = result[i - 1] * nums[i - 1];

    int current = 0;
    for (int i = nums.size() - 2; i >= 0; --i) {
        if (i == nums.size() - 2) current = nums[i + 1];
        else current = current * nums[i + 1];
        if (i > 0) result[i] *= current;
        else result[i] = current;
    }

    return result;
}