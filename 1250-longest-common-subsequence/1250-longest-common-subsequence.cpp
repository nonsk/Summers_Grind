class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1_len = text1.length(), text2_len = text2.length();
        int prev[text2_len + 1], curr[text2_len + 1];
        int i, j;

        memset(prev, 0, sizeof(prev));
        memset(curr, 0, sizeof(curr));

        for (i = 1; i <= text1_len; ++i) {
            for (j = 1; j <= text2_len; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = prev[j - 1] + 1;
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }

            memcpy(prev, curr, sizeof(prev));
            memset(curr, 0, sizeof(prev));
        }

        return prev[text2_len];
    }
};