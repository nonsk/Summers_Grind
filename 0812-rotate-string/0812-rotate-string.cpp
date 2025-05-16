class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal) return true;
        for(int i =0; i<s.size(); i++){
            cout<<s<<endl;
            char c = s[0];
            s = s.substr(1,s.size()-1) + c;
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};