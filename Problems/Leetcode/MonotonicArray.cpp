//
// Created by Emanuel on 25.10.2021.
//

#include <vector>
using namespace std;

class Solution {
public:
    int sgn(int a) {
        if (!a) return 0;
        return a > 0 ? 1 : -1;
    }

    bool isMonotonic(vector<int>& nums) {
        if (nums.size() < 2)
            return true;

        int i = 1;
        while (i < nums.size() && nums[i - 1] == nums[i]) {
            i++;
        }

        if (i == nums.size())
            return true;

        int diff = nums[i - 1] - nums[i];
        for (i; i < nums.size(); ++i) {
            if (!sgn(nums[i - 1] - nums[i]))
                continue;
            if (sgn(nums[i - 1] - nums[i]) != sgn(diff))
                return false;
        }

        return true;
    }
};