//
// Created by Emanuel on 14.02.2022.
//

#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int crt = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[crt - 1] != nums[i]) {
                nums[crt] = nums[i];
                crt++;
            }

            // optimization
            if (nums[nums.size() - 1] == nums[i])
                break;
        }

        return crt;
    }
};
