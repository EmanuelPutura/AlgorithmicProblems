//
// Created by Emanuel on 14.09.2022.
//

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, n = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            }

            if (nums[m] > nums[n]) {
                // this means we are in the bigger part of the array
                if (target > nums[m] || target <= nums[n]) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
            else {
                if (target < nums[m] || target > nums[n]) {
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }

        return -1;
    }
};