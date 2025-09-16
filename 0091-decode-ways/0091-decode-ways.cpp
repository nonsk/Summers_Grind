class Solution {
public:
    unordered_map<string, int> mp;
    int recur(string s) {
        if (mp.find(s) != mp.end())
            return mp[s];
        if (s.size() == 0)
            return 1;
        if (s.size() == 1) {
            if (s[0] == '0')
                return 0;
            else {
                return 1;
            }
        }
        if (s.size() == 2) {
            int num = (s[0] - '0') * 10 + s[1] - '0';
            if (num <= 26) {

                // 01,02,03,04,...
                if (s[0] == '0')
                    return 0;
                // 10,20,
                if (s[1] == '0')
                    return 1;
                // 11, 23, 12
                return 2;
            } else {
                // 30,40,50,60...
                if (s[0] == '0' || s[1] == '0') {
                    return 0;
                } else {
                    // 28,27,29...
                    return 1;
                }
            }
        }

        // one
        int one = 0;
        if (s[0] != '0') {
            one = recur(s.substr(1, s.size() - 1));
        }
        // two
        int two = 0;
        int num = (s[0] - '0') * 10 + s[1] - '0';
        if (s[0] != '0' &&num <= 26) {
            two = recur(s.substr(2, s.size() - 2));
        }
        mp[s] = one + two;
        return one + two;
    }
    int numDecodings(string s) { return recur(s); }
};