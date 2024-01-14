// Problem: https://leetcode.com/problems/determine-if-two-strings-are-close/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool closeStrings(string s, string t) {
        vector<int> cnt1(26), cnt2(26);
        for (auto& x : s) cnt1[x - 'a']++;
        for (auto& x : t) cnt2[x - 'a']++;

        for (int i = 0; i < 26; i++) {
            if ((!cnt1[i] && cnt2[i]) || (!cnt2[i] && cnt1[i])) {
                return false;
            }
        }    

        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());

        for (int i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                return false;
            }
        }

        return true;
    }
};
