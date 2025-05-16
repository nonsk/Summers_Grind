class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int count = 0;
        for (int j = 0; ; j++) {
            if (j >= strs[0].size()) return strs[0].substr(0, count);
            char current = strs[0][j];
            for (int i = 1; i < strs.size(); i++) {
                if (j >= strs[i].size() || strs[i][j] != current) {
                    return strs[0].substr(0, count);
                }
            }
            count++;
        }

        return "";
    }
};
