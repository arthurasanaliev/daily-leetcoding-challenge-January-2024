// Problem: https://leetcode.com/problems/longest-increasing-subsequence/

// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j && nums[i] <= nums[j - 1]) {
                *lower_bound(nums.begin(), nums.begin() + j, nums[i]) = nums[i]; 
            } else {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};
