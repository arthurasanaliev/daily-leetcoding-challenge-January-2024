// Problem: https://leetcode.com/problems/insert-delete-getrandom-o1/

// Time Complexity: O(1)
// Space Complexity: O(n)

class RandomizedSet {
public:
    unordered_set<int> st;

    RandomizedSet() {
        
    }

    bool insert(int val) {
        if (st.count(val)) return false;
        st.insert(val);
        return true;
    }

    bool remove(int val) {
        if (!st.count(val)) return false;
        st.erase(val);
        return true;
    }

    int getRandom() {
        int n = rand() % st.size();
        auto it = st.begin();
        advance(it, n);
        return *it;
    }
};
