//
// Created by Emanuel on 23.10.2021.
//

#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int max = 1, current = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                current++;
                if (current > max)
                    max = current;
            }
            else {
                current = 1;
            }
        }

        return max;
    }
};