class Solution {
public:
    void f(int i, string s, vector<string>& ans, string& digits) {
        cout << s << endl;
        if (s.size() == digits.size()) {
            ans.push_back(s);
            return;
        }
        switch (digits[i]) {
        case '2':
            f(i + 1, s + "a", ans, digits);
            f(i + 1, s + "b", ans, digits);
            f(i + 1, s + "c", ans, digits);
            break;
        case '3':
            f(i + 1, s + "d", ans, digits);
            f(i + 1, s + "e", ans, digits);
            f(i + 1, s + "f", ans, digits);
            break;
        case '4':
            f(i + 1, s + "g", ans, digits);
            f(i + 1, s + "h", ans, digits);
            f(i + 1, s + "i", ans, digits);
            break;
        case '5':
            f(i + 1, s + "j", ans, digits);
            f(i + 1, s + "k", ans, digits);
            f(i + 1, s + "l", ans, digits);
            break;
        case '6':
            f(i + 1, s + "m", ans, digits);
            f(i + 1, s + "n", ans, digits);
            f(i + 1, s + "o", ans, digits);
            break;
        case '7':
            f(i + 1, s + "p", ans, digits);
            f(i + 1, s + "q", ans, digits);
            f(i + 1, s + "r", ans, digits);
            f(i + 1, s + "s", ans, digits);
            break;
        case '8':
            f(i + 1, s + "t", ans, digits);
            f(i + 1, s + "u", ans, digits);
            f(i + 1, s + "v", ans, digits);
            break;
        case '9':
            f(i + 1, s + "w", ans, digits);
            f(i + 1, s + "x", ans, digits);
            f(i + 1, s + "y", ans, digits);
            f(i + 1, s + "z", ans, digits);
            break;
        default:
            return;
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits == "") {
            return ans;
        }
        f(0, "", ans, digits);
        return ans;
    }
};