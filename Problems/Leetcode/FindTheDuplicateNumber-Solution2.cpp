//
// Created by Emanuel on 26.04.2022.
//

/*
    Solution 2: Floyd's Tortoise and Hare Cycle Detection Algorithm
    Time Complexity: O(n)
    Extra-space Complexity: O(1)

    - this solution does NOT change the order of the elements, thus respecting the problem statement
*/

#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int n = nums.size() - 1;
        int hare = n + 1, tortoise = n + 1;

        // detect the cycle
        do {
            hare = nums[hare - 1];
            tortoise = nums[nums[tortoise - 1] - 1];
        } while (hare != tortoise);

        // detect the start of the cycle
        hare = n + 1;
        while (hare != tortoise) {
            hare = nums[hare - 1];
            tortoise = nums[tortoise - 1];
        }

        return hare;
    }
};
