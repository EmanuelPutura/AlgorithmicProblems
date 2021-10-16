//
// Created by Emanuel on 16.10.2021.
//

#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> wdn;

        for (int i = 0; i < nums.size(); ++i) {
            while (!wdn.empty() && wdn.back() < nums[i]) {
                wdn.pop_back();
            }

            wdn.push_back(nums[i]);
            if (i >= k - 1) {
                result.push_back(wdn.front());
                if (wdn.front() == nums[i - k + 1]) wdn.pop_front();
            }
        }

        return result;
    }
};