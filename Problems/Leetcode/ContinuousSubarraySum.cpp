//
// Created by Emanuel on 10.11.2021.
//

class Solution1 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> modk;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (modk.count(mod)) return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};

class Solution2 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;
        std::unordered_map<int, int> modulos;
        // std::vector<int> modulos (k, -1);

        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        int left_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            left_sum += nums[i];
            if (left_sum % k == 0 && i > 0) {
                return true;
            }
            modulos[(sum - left_sum) % k] = i;
        }

        int right_sum = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            right_sum += nums[i];
            if (right_sum % k == 0 && i < nums.size() - 1) {
                return true;
            }
            if (modulos.find(right_sum % k) != modulos.end() && i < modulos[right_sum % k]) {
                return true;
            }
        }

        return false;
    }
};