//
// Created by Emanuel on 14.10.2021.
//

#include <vector>

bool isDefined(int first_limit, int index) {
    return first_limit >= index;
}

bool increasingTriplet(std::vector<int>& nums) {
    bool result = false;
    std::vector<int> first (3), second (3);
    int first_limit = -1, second_limit = -1;  // limit = i <=> first/second[0..i] is well defined

    int index = 0;
    first_limit++;
    first[0] = nums[index];

    // while the second element from the first sequence is not well defined
    while (index < nums.size() && !isDefined(first_limit, 1)) {
        if (nums[index] <= first[0])
            first[0] = nums[index];
        else {
            first[1] = nums[index];
            first_limit++;
        }
        index++;
    }

    while (index < nums.size()) {
        // while the first element from the second sequence is not well defined
        while (index < nums.size() && !isDefined(second_limit, 0)) {
            if (nums[index] > first[1])
                return true;
            if (nums[index] > first[0])
                first[1] = nums[index];
            else if (nums[index] < first[0]) {
                second[0] = nums[index];
                second_limit++;
            }
            index++;
        }

        // while the second element from the second sequence is not well defined
        while (index < nums.size() && !isDefined(second_limit, 1)) {
            if (nums[index] > first[1])
                return true;
            if (nums[index] > first[0])
                first[1] = nums[index];
            else if (nums[index] > second[0]) {
                first[0] = second[0];
                first[1] = nums[index];
                second_limit = -1;
                index++;
                break;
            }
            else if (nums[index] < second[0])
                second[0] = nums[index];
            index++;
        }
    }

    return result;
}