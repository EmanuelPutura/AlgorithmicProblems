//
// Created by Emanuel on 04.10.2021.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        std::vector<char> values = {'T', 'F'};
        int max = 0;

        for (const auto& value : values) {
            int start = 0, cnt = 0, len = 0;
            for (int i = 0; i < answerKey.length(); ++i) {
                if (answerKey[i] == value) {
                    cnt++;
                    if (cnt > k) {
                        while (answerKey[start] != value) {
                            len--;
                            start++;
                        }

                        len--;
                        start++;
                        cnt--;
                    }
                }

                len++;
                if (len > max)
                    max = len;
            }
        }

        return max;
    }
};
