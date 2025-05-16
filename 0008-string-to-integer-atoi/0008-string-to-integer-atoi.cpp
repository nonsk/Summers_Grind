class Solution {
public:
    void helper(string s, long long& ans, bool& neg, bool& start) {
        if (s == "") return;

        if (!start) {
            if (s[0] == ' ') {
                helper(s.substr(1), ans, neg, start);
                return;
            } else if (s[0] == '-') {
                neg = true;
                start = true;
            } else if (s[0] == '+') {
                start = true;
            } else if (s[0] >= '0' && s[0] <= '9') {
                start = true;
                ans = ans * 10 + (s[0] - '0');
            } else {
                return;
            }
            helper(s.substr(1), ans, neg, start);
            return;
        }

        if (s[0] >= '0' && s[0] <= '9') {
            int digit = s[0] - '0';
            ans = ans * 10 + digit;
            if (!neg && ans > INT_MAX) {
                ans = INT_MAX;
                return;
            }
            if (neg && -ans < INT_MIN) {
                ans = -(long long)INT_MIN;
                return;
            }
            helper(s.substr(1), ans, neg, start);
            return;
        } else {
            return;
        }
    }

    int myAtoi(string s) {
        bool neg = false;
        long long ans = 0;
        bool start = false;
        helper(s, ans, neg, start);
        if (neg) ans = -ans;
        if (ans < INT_MIN) return INT_MIN;
        if (ans > INT_MAX) return INT_MAX;
        return (int)ans;
    }
};
