//
// Created by Emanuel on 16.10.2021.
//

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
    std::vector<std::vector<int>> result;

    int min = std::abs(arr[1] - arr[0]);
    for (int i = 2; i < arr.size(); ++i) {
        if (std::abs(arr[i] - arr[i - 1]) < min) {
            min = std::abs(arr[i] - arr[i - 1]);
        }
    }

    for (int i = 1; i < arr.size(); ++i) {
        if (std::abs(arr[i] - arr[i - 1]) == min) {
            result.push_back(std::vector<int> {arr[i - 1], arr[i]});
        }
    }

    return result;
}

/*vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    const int LIMIT = 1000000;
    std::unordered_set<int> found;
    std::vector<std::vector<int>> result;

    int min = -LIMIT, max = LIMIT;
    for (int i = 0; i < arr.size(); ++i) {
        found.insert(arr[i]);

        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    int dist = 0, min_dist = 2 * LIMIT + 1;
    for (int c = min + 1; c <= max; ++c) {
        if (found.find(c) == found.end())
            dist++;
        else {
            if (dist < min_dist)
                min_dist = dist;
            dist = 1;
        }
    }

    int last = min;
    for (int c = min + 1; c <= max; ++c) {
        if (found.find(c) == found.end())
            dist++;
        else {
            if (dist == min_dist)
                result.push_back(std::vector<int> {last, c});

            last = c;
            dist = 1;
        }
    }

    return result;
}*/