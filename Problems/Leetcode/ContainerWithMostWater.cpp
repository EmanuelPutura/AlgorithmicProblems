//
// Created by Emanuel on 25.07.2022.
//

#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        int left = 0, right = heights.size() - 1;
        int maxWater = -1, current = -1;

        while (left < right) {
            current = std::min(heights[left], heights[right]) * (right - left);
            if (current > maxWater) {
                maxWater = current;
            }

            if (heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxWater;
    }
};
