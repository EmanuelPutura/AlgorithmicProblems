cmake_minimum_required(VERSION 3.16)
project(Problems)

set(CMAKE_CXX_STANDARD 17)

add_executable(Problems Leetcode/LongestPalindromicSubstring.cpp Leetcode/main.cpp Leetcode/ValidParentheses.cpp Leetcode/PalindromeLinkedList.cpp Leetcode/LongestSubstringWithoutRepeatingCharacters.cpp)