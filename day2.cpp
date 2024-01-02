// Problem: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n + 1);

        vector<vector<int>> ans;
        for (auto& num : nums) {
            if (cnt[num] >= (int)ans.size()) {
                ans.push_back({});
            }
            ans[cnt[num]].push_back(num);
            cnt[num]++;
        }

        return ans;
    }
};
