// Problem: https://leetcode.com/problems/unique-number-of-occurrences/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto& x : arr) mp[x]++;

        unordered_set<int> st;
        for (auto& [val, num] : mp) {
            if (st.count(num)) return false;
            st.insert(num);
        }

        return true;
    }
};
