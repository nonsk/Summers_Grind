class Solution {
public:
    string removeOuterParentheses(string s) {
        int o = 0;
        int c = 0;
        string temp = "";
        string ans;
        for(auto it : s){
            if(it=='('){
                o++;
            }
            else{
                c++;
            }
            temp += it;
            if(o==c && c!=0){
                temp = temp.substr(1, temp.length() - 2);
                ans += temp;
                temp = "";
            }
        }
        return ans;
    }
};