class Solution {
public:
    void helper(int o, int c, int n, vector<string>& ans, string s) {
        if (s.length() == 2 * n) {
            ans.push_back(s);
            // cout << s << endl;
            return;
        }
        if (c > o) {
            return;
        }
        if (o == n) {
            helper(o, c + 1, n, ans, s + ")");
        }
        else{helper(o + 1, c, n, ans, s + "(");
        helper(o, c + 1, n, ans, s + ")");}
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(0, 0, n, ans, "");
        return ans;
    }
};