//
// Created by Emanuel on 23.10.2021.
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = -0x3f3f3f3f, negative_product = 1, positive_product = 1, start = 0;
        bool found = false;

        for (int i = 0; i <= nums.size(); ++i) {
            if ((i == nums.size() || nums[i] == 0)) {
                if (i == 0) {
                    start++;
                    continue;
                }
                if (negative_product > 0 && i > 0 && nums[i - 1] != 0) {
                    if (negative_product * positive_product > result)
                        result = negative_product * positive_product;
                }
                else {
                    if (i > 0 && nums[i - 1] == 0) {
                        start++;
                        continue;
                    }

                    int current = negative_product * positive_product, index = i - 1;
                    while (index > start && current < 0) {
                        current /= nums[index];
                        index--;
                    }

                    result = std::max(result, current);
                    if (i < nums.size() && nums[i] == 0 && result < 0)
                        result = 0;

                    current = negative_product * positive_product;
                    index = start;

                    while (index < i - 1 && current < 0) {
                        current /= nums[index];
                        index++;
                    }

                    result = std::max(result, current);

                }

                start = i + 1;
                negative_product = 1;
                positive_product = 1;
                continue;
            }

            if (nums[i] > 0) {
                positive_product *= nums[i];
                found = true;
            }
            else if (nums[i] != 0) {
                negative_product *= nums[i];
                found = true;
            }
        }

        if (found)
            return result;
        return 0;
    }
};