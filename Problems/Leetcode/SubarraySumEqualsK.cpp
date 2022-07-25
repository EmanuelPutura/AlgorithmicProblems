//
// Created by Emanuel on 25.07.2022.
//

#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(const std::vector<int>& nums, int k) {
        std::vector<int> sumUntil(nums.size());
        std::unordered_map<int, int> sumUntilCntMap;

        int cnt = (nums.size() > 0 && nums[0] == k) ? 1 : 0;

        sumUntil[0] = nums[0];
        sumUntilCntMap[-nums[0]] = 1;

        for (int i = 1; i < nums.size(); ++i) {
            sumUntil[i] = sumUntil[i - 1] + nums[i];
            if (sumUntil[i] == k) {
                cnt++;
            }

            auto it = sumUntilCntMap.find(k - sumUntil[i]);
            if (it != sumUntilCntMap.end()) {
                cnt += it->second;
            }

            sumUntilCntMap[-sumUntil[i]]++;
        }

        return cnt;
    }
};
