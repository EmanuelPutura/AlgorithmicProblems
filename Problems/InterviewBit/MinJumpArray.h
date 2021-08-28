//
// Created by Emanuel on 28.08.2021.
//

/*
 * Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Return the minimum number of jumps required to reach the last index.
 * If it is not possible to reach the last index, return -1.
 */

#ifndef PROBLEMS_MINJUMPARRAY_H
#define PROBLEMS_MINJUMPARRAY_H

#include <vector>

// O(n) solution
int jump(std::vector<int> &A);
void testMinJumpArray();

#endif //PROBLEMS_MINJUMPARRAY_H
