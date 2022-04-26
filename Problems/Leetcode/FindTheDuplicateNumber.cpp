//
// Created by Emanuel on 26.04.2022.
//

/*
    Solution 1
    Time Complexity: O(n)
    Extra-space Complexity: O(1)

    - this solution changes the order of the elements
*/

#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (i + 1 == nums[i]) {
                continue;
            }

            if (nums[nums[i] - 1] == nums[i]) {
                return nums[i];
            }
            else {
                std::swap(nums[nums[i] - 1], nums[i]);
                i--;
            }
        }

        return -1;
    }
};

