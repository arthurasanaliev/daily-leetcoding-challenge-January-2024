// Problem: https://leetcode.com/problems/set-mismatch/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> used;
        
        vector<int> ans;
        for (auto& num : nums) {
            if (used.count(num)) {
                ans.push_back(num);
            }
            used.insert(num);
        }

        for (int i = 1; i <= n; i++) {
            if (!used.count(i)) {
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};
