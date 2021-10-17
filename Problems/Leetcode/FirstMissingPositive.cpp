//
// Created by Emanuel on 17.10.2021.
//

#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    /*
        Let r be the result. Then 1 <= r <= n + 1.
        Also note that 1, 2, ..., r - 1 must then be in nums.
        Iterate through the elements. At each current element, swap it with the element from position current - 1, if:
        1) 1 <= current <= n
        2) nums[current - 1] != current
        Continue now with the element swapped to the last position of current (if the swap happened).
        Else, just let the number at its place and continue.
        At the end, the first element that it is not on position element - 1 is the answer of the problem.
    */

    // still O(n) because each element is swapped at most once
    for (int i = 0; i < nums.size(); ++i) {
        while (0 < nums[i] && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
            std::swap(nums[i], nums[nums[i] - 1]);
    }

    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] != i + 1)
            return i + 1;

    return nums.size() + 1;
}