// Problem: https://leetcode.com/problems/climbing-stairs/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int climbStairs(int n) {
        int one = 0, two = 1;
        for (int i = 0; i < n; i++) {
            int tmp = one;
            one = two;
            two += tmp;
        }

        return two;
    }
};
