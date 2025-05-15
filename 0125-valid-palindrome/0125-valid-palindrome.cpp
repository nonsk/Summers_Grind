class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;
        for (auto it : s) {
            if (isalnum(it)) {
                cleaned += it;
            }
        }
        for (auto& c : cleaned) {
            c = tolower(c);
        }
        string yo = cleaned;
        reverse(cleaned.begin(), cleaned.end());
        for (int i = 0; i < cleaned.size(); i++) {
            if (cleaned[i] != yo[i]) {
                return false;
            }
        }
        return true;
    }
};