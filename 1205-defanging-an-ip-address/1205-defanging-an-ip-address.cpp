class Solution {
public:
    string defangIPaddr(string address) {
        string s = "";
        for(auto it : address){
            if(it=='.'){
                s+="[.]";
            }
            else{
                s+=it;
            }
        }
        return s;
    }
};