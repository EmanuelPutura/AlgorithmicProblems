//
// Created by Emanuel on 16.10.2021.
//

#include <vector>
#include <unordered_map>
#include <unordered_set>

bool uniqueOccurrences(std::vector<int>& arr) {
    const int DIM = 1001;
    std::unordered_set<int> occurs;
    std::unordered_map<int, int> cnt;

    for (int i = 0; i < arr.size(); ++i)
        cnt[arr[i]]++;
    for (int i = 0; i < arr.size(); ++i) {
        if (cnt[arr[i]] == -1) continue;
        if (occurs.find(cnt[arr[i]]) != occurs.end()) return false;
        occurs.insert(cnt[arr[i]]);
        cnt[arr[i]] = -1;
    }

    return true;
}