class Solution {
public:
    bool helper(string cleaned) {
        string yo = cleaned;
        reverse(cleaned.begin(), cleaned.end());
        for (int i = 0; i < cleaned.size(); i++) {
            if (cleaned[i] != yo[i]) {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        return helper(to_string(x));
    }
};