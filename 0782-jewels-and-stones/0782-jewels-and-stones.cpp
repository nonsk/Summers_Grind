class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> m;
        for (int i = 0; i < stones.size(); i++) {
                m[stones[i]] += 1;
        }
        int ans = 0;
        for (auto it : jewels) {
            ans += m[it];
        }
        return ans;
    }
};